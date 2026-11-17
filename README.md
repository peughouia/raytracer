# Raytracer Live Demo 2026

> **Context:** Une équipe développe un outil de rendu (*ray tracer*) pour un studio qui produit des films d’animation pour enfants. Les designers ont déjà storyboardé et modélisé les scènes en 3D (à base de triangles) ; il reste à les rendre. Notre rôle est de comprendre le besoin réel et résoudre les potentiels problèmes (voir [docs/discovery/discovery-report.md](file:///d:/MT5%20HETIC/raytracer/docs/discovery/discovery-report.md)).

---

## 1. Cross-Platform Compilation Strategy

To ensure seamless collaboration across student workstations (Windows, macOS Intel/Apple Silicon, and Linux) without environment mismatches or path friction, the project employs a **two-tier cross-platform strategy**:

```
+--------------------------------------------------------------------------+
|  Tier 1 (Recommended): Dev Containers (Docker)                          |
|  - Identical toolchain: Ubuntu 24.04, GCC 14, Clang 18, CMake 3.28, GDB  |
|  - Supported in VS Code, Zed, and GitHub Codespaces                      |
+--------------------------------------------------------------------------+
                                    |
                                    v
+--------------------------------------------------------------------------+
|  Tier 2 (Native): Modern CMake 3.20+ (C++20)                             |
|  - Portable standard CMakeLists.txt and CMakePresets.json                |
|  - Works with GCC, Clang, and MSVC                                       |
+--------------------------------------------------------------------------+
```

### Why Dev Containers?
- **Zero "Works on my machine" issues:** Every contributor gets the exact same compiler version, standard library, and build tools.
- **Zero manual dependency installation:** CMake, Ninja, Catch2, GDB, Valgrind, and `clang-format` are ready instantly.
- **Editor agnostic:** Works seamlessly with **VS Code** (Dev Containers extension) and **Zed** (container workflows).

---

## 2. Project Layout

```text
raytracer/
├── .devcontainer/
│   ├── devcontainer.json       # Dev Container configuration (extensions, settings)
│   └── Dockerfile              # C++20 container image with GCC, CMake, Ninja, GDB
├── .vscode/
│   ├── extensions.json         # Recommended VS Code extensions
│   ├── launch.json             # Debugger profiles for demo and test suite
│   ├── settings.json           # CMake and Catch2 Test Adapter settings
│   └── tasks.json              # Quick build & test tasks
├── docs/
│   └── discovery/              # Discovery report and specifications
├── include/
│   └── raytracer/
│       └── hello.hpp           # Public headers & declarations (namespace raytracer)
├── src/
│   ├── hello.cpp               # Core library implementation
│   └── main.cpp                # Demo entry point executable
├── tests/
│   └── test_hello.cpp          # Unit and BDD tests using Catch2 v3
├── CMakeLists.txt              # Modern CMake build definition (C++20)
├── CMakePresets.json           # Standard debug & release configuration presets
├── Makefile                    # Convenience shortcuts for terminal users
└── README.md                   # This documentation
```

---

## 3. Quickstart: Compile & Run Hello World

### Option A: Using VS Code Dev Containers (Recommended)

1. Ensure **Docker Desktop** (or Podman / Docker Engine) is installed and running.
2. Open this folder in **VS Code**.
3. When prompted with *"Folder contains a Dev Container configuration file. Reopen in Container?"*, click **Reopen in Container** (or press `F1` / `Ctrl+Shift+P` / `Cmd+Shift+P` and select `Dev Containers: Reopen in Container`).
4. VS Code opens inside the Linux container with all tools pre-configured:
   - Press `Ctrl+Shift+B` (or `Cmd+Shift+B`) to build the project.
   - Run in the integrated terminal:
     ```bash
     ./build/bin/raytracer
     ```
   - Or press `F5` to launch the interactive debugger (`gdb`).

### Option B: Using Zed

Zed supports development inside Docker containers through the Dev Container CLI or Docker exec:

1. Launch your dev container:
   ```bash
   # From the project root
   docker build -t raytracer-dev .devcontainer
   docker run -it --rm -v "$(pwd):/workspaces/raytracer" -w /workspaces/raytracer raytracer-dev bash
   ```
2. Inside the container (or from Zed terminal):
   ```bash
   cmake -B build -S .
   cmake --build build
   ./build/bin/raytracer
   ```

### Option C: Native Host Compilation (No Docker)

If you have a local C++20 compiler (`g++`, `clang++`, or MSVC) and `cmake` (>= 3.20) installed:

#### Linux (Debian / Ubuntu)
```bash
sudo apt update && sudo apt install -y build-essential cmake ninja-build git
cmake -B build -S .
cmake --build build
./build/bin/raytracer
```

#### macOS (Apple Silicon / Intel)
```bash
brew install cmake ninja
cmake -B build -S .
cmake --build build
./build/bin/raytracer
```

#### Windows (PowerShell with MSYS2 / UCRT64 or Visual Studio)
```powershell
# Using CMake with MinGW / UCRT64 / Ninja:
cmake -B build -S .
cmake --build build
.\build\bin\raytracer.exe
```

### Option D: Convenience Makefile

If you prefer simple `make` shortcuts:
```bash
make          # Configures and builds everything
make run      # Runs the Hello World demo
make test     # Runs the test suite via CTest
make clean    # Cleans build artifacts
```

### Expected Output
When running the executable (`raytracer`), you will see:
```text
========================================
Hello, World! Welcome to the Raytracer project.
========================================

Raytracer v0.1.0
Standard: C++20
Architecture: Cross-platform (Linux / macOS / Windows)

Demo vector computation:
  v1 = (1, 2, 3)
  v2 = (4, 5, 6)
  v1 + v2 = (5, 7, 9)
  v1 . v2 = 32

Project bootstrapped successfully! Ready for raytracing development.
```

---

## 4. Test-Driven Development (TDD) with Catch2

### Why Catch2 v3?
- **Zero manual installation:** Automatically fetched and configured by CMake via `FetchContent`.
- **Human-readable assertions:** `REQUIRE(value == 42)` instead of verbose macros.
- **BDD (Behavior-Driven Development) support:** `SCENARIO`, `GIVEN`, `WHEN`, `THEN` keywords align directly with client user stories.
- **Hierarchical `SECTION` blocks:** Allows test cases to share setup code cleanly without complex fixture classes.
- **Fast and granular:** Can execute individual tests, tag selections, or the entire suite.

### How to Run Tests

#### 1. Via CTest (CMake standard test runner)
```bash
ctest --test-dir build --output-on-failure
```

#### 2. Directly via the test binary (Catch2 CLI)
```bash
# Run all tests
./build/bin/raytracer_tests

# Run tests with a specific tag (e.g. only greeting tests)
./build/bin/raytracer_tests [greeting]

# Run tests with BDD vector math tag
./build/bin/raytracer_tests [vec3]

# List all available test cases
./build/bin/raytracer_tests --list-tests

# List all test tags
./build/bin/raytracer_tests --list-tags
```

#### 3. Via VS Code Test Explorer
The `.vscode/settings.json` file is configured with the Catch2 Test Adapter. Open the **Testing** tab (flask icon) in the VS Code sidebar to view, run, and debug individual tests with a single click.

---

## 5. Step-by-Step TDD Workflow

We follow the classic **Red-Green-Refactor** loop for all raytracer components (vectors, rays, camera, intersections, shading):

```
       +---------------------------------------------+
       | 1. RED: Write a failing unit test first     |
       +---------------------------------------------+
                              |
                              v
       +---------------------------------------------+
       | 2. GREEN: Implement minimal working code    |
       +---------------------------------------------+
                              |
                              v
       +---------------------------------------------+
       | 3. REFACTOR: Improve design and performance |
       +---------------------------------------------+
                              |
                              +---> (Loop back to 1)
```

### Concrete Example: Adding Vector Length (`Vec3::length()`)

#### Step 1: Write the failing test (**RED**)
In [tests/test_hello.cpp](file:///d:/MT5%20HETIC/raytracer/tests/test_hello.cpp), add a new specification:

```cpp
TEST_CASE("Vec3 calculates Euclidean length", "[math][vec3]") {
    raytracer::Vec3 v{3.0, 4.0, 0.0};
    
    // Expect length to be 5.0 (3-4-5 triangle)
    REQUIRE(v.length() == Catch::Approx(5.0));
}
```
Run `make test` or `ctest --test-dir build --output-on-failure`.
> **Result:** Compilation fails or test fails because `v.length()` does not exist yet. **(Red phase confirmed)**

#### Step 2: Write minimal implementation (**GREEN**)
In [include/raytracer/hello.hpp](file:///d:/MT5%20HETIC/raytracer/include/raytracer/hello.hpp), add the method to `struct Vec3`:

```cpp
#include <cmath>

struct Vec3 {
    // ... existing fields ...

    double length() const {
        return std::sqrt(dot(*this));
    }
};
```
Re-run tests:
```bash
ctest --test-dir build --output-on-failure
```
> **Result:** All tests pass! **(Green phase confirmed)**

#### Step 3: Refactor (**REFACTOR**)
Clean up formatting, check edge cases (e.g. zero length vector, normalization), verify compiler warnings with `-Wall -Wextra`, and commit your changes.

---

## 6. Code Quality & Formatting

To maintain clean code across all contributors:
- **Formatter:** `clang-format` is pre-configured. In VS Code, files format automatically upon saving.
- **Compiler Warnings:** Configured with `-Wall -Wextra -Wpedantic -Wconversion -Wshadow` (GCC/Clang) and `/W4` (MSVC) in `CMakeLists.txt`. Treat warnings as issues to solve immediately.
