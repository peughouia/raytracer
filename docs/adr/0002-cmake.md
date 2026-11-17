# 2. Use CMake and CTest for Building and Testing

## Context
The project needs a way to compile modern C++ code and execute test suites across multiple operating systems. We considered alternatives such as writing raw Makefiles, maintaining separate platform-specific IDE project files (Visual Studio solutions, Xcode projects), or using alternative build generators like Meson or Bazel.

## Decision
We will use CMake as our build system generator and CTest as our test runner. CMake describes the build and generates the build files for each platform. CTest comes with CMake, runs the test programs, and reports pass or fail.

## Status
Proposed

## Consequences
Build specifications and targets are unified in a single cross-platform configuration file (`CMakeLists.txt`), and tests can be orchestrated with a standard `ctest` command.
However, CMake has a non-trivial learning curve, and diagnosing configuration or generator errors can be challenging for beginners.
