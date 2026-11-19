cmake_minimum_required(VERSION 3.20)

project(Raytracer
    VERSION 0.1.0
    DESCRIPTION "A modern C++ raytracer project for educational animation rendering"
    LANGUAGES CXX
)

# Enforce Modern C++20 Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for IDEs (clangd, Zed, VS Code)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Configure common warning flags for our targets (keeps external dependencies like Catch2 clean)
add_library(project_warnings INTERFACE)
if(MSVC)
    target_compile_options(project_warnings INTERFACE /W4 /permissive-)
else()
    target_compile_options(project_warnings INTERFACE -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
endif()

# ==============================================================================
# Raytracer Core Library
# ==============================================================================
# All modular raytracing logic (math, rays, cameras, objects) goes here.
# This makes unit testing straightforward and decoupled from main().
add_library(raytracer_core
    src/raytracer/hello.hpp
    src/raytracer/hello.cpp
    src/math/vector.h
    src/math/vector.cpp
    src/colour.h
    src/colour.cpp
    src/ray.h
    src/ray.cpp
    src/sphere.h
    src/sphere.cpp
    src/camera.h
    src/camera.cpp
)

target_link_libraries(raytracer_core PUBLIC
    project_warnings
)

target_include_directories(raytracer_core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
)

# ==============================================================================
# Main Executable Demo
# ==============================================================================
add_executable(raytracer
    src/main.cpp
)

target_link_libraries(raytracer PRIVATE
    raytracer_core
)

# Set output directory convenience
set_target_properties(raytracer PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# ==============================================================================
# Testing Suite (TDD via Catch2 v3)
# ==============================================================================
include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    # Fetch Catch2 v3 automatically (zero manual install needed)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.5.2
    )
    FetchContent_MakeAvailable(Catch2)

    add_executable(raytracer_tests
        tests/raytracer/test_hello.cpp
        tests/math/test_vector.cpp
    )

    target_link_libraries(raytracer_tests PRIVATE
        raytracer_core
        Catch2::Catch2WithMain
    )

    set_target_properties(raytracer_tests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )

    # Automatically register Catch2 tests with CTest
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
    include(Catch)
    catch_discover_tests(raytracer_tests)
endif()
