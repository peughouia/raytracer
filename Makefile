# Convenience Makefile wrapping CMake workflows
# (Useful in devcontainers, Linux, macOS, and MSYS2)

BUILD_DIR ?= build
BUILD_TYPE ?= Debug

.PHONY: all configure build run test clean help

all: build

help:
	@echo "Available targets:"
	@echo "  make configure   - Run CMake configuration in $(BUILD_DIR)/"
	@echo "  make build       - Compile the library, executable, and test suite"
	@echo "  make run         - Run the Hello World demo executable"
	@echo "  make test        - Run unit tests via CTest"
	@echo "  make clean       - Remove build directories"

configure:
	@if command -v ninja >/dev/null 2>&1; then \
		cmake -B $(BUILD_DIR) -S . -G Ninja -DCMAKE_BUILD_TYPE=$(BUILD_TYPE); \
	else \
		cmake -B $(BUILD_DIR) -S . -DCMAKE_BUILD_TYPE=$(BUILD_TYPE); \
	fi

build: configure
	cmake --build $(BUILD_DIR)

run:
	@if [ -f $(BUILD_DIR)/unix-debug/bin/raytracer ]; then \
		$(BUILD_DIR)/unix-debug/bin/raytracer; \
	elif [ -f $(BUILD_DIR)/bin/raytracer ]; then \
		$(BUILD_DIR)/bin/raytracer; \
	elif [ -f $(BUILD_DIR)/unix-debug/bin/raytracer.exe ]; then \
		$(BUILD_DIR)/unix-debug/bin/raytracer.exe; \
	elif [ -f $(BUILD_DIR)/bin/raytracer.exe ]; then \
		$(BUILD_DIR)/bin/raytracer.exe; \
	else \
		cmake --build $(BUILD_DIR) && \
		if [ -f $(BUILD_DIR)/bin/raytracer ]; then \
			$(BUILD_DIR)/bin/raytracer; \
		else \
			echo "Executable not found in $(BUILD_DIR)/bin/"; exit 1; \
		fi \
	fi

test:
	@if [ -d $(BUILD_DIR)/unix-debug ] && [ -f $(BUILD_DIR)/unix-debug/CTestTestfile.cmake ]; then \
		ctest --test-dir $(BUILD_DIR)/unix-debug --output-on-failure; \
	else \
		ctest --test-dir $(BUILD_DIR) --output-on-failure; \
	fi

clean:
	rm -rf $(BUILD_DIR) build-release
