# 5. Structure Source and Test Folders by Concept

## Context
A single flat `src/` directory does not scale as the raytracer grows to encompass geometry, materials, lighting, cameras, and math. We want developers to easily find any class and its corresponding tests by looking under the concept it belongs to.

## Decision
- Source code is organized with one folder per concept directly under `src/` (e.g., `src/math/`, `src/geometry/`, `src/render/`).
- The `tests/` directory mirrors this structure identically (e.g., `tests/math/`).
- All header inclusions use paths relative to `src/` (e.g., `#include "math/vector.h"`).
- `src/main.cpp` remains at the root of `src/` as the single executable entry point.

## Status
Proposed

## Consequences
- Codebase navigation is intuitive and predictable: finding a concept immediately locates both its implementation and its tests.
- Include paths are self-documenting and prevent ambiguous header names.
- **Downsides:**
  - Deeper directory hierarchy adds slight file path verbosity.
  - Adding a new class requires determining or creating the appropriate concept folder.

## What We Deliberately Left Out For Now
1. **Namespaces per folder:**
   - *Why left out:* Keeps C++ simple and accessible for beginners without requiring verbose qualifications or extensive `using` statements.
   - *When it becomes worth it:* When symbol name collisions occur across domains or when the project is prepared for external consumers.
2. **One CMake library target per folder:**
   - *Why left out:* A single `raytracer_core` library avoids target dependency wiring, link ordering complexities, and CMake boilerplate.
   - *When it becomes worth it:* When build times become significant and modular compilation caching provides noticeable speedups.
3. **A separate `include/` folder:**
   - *Why left out:* Co-locating `.h` and `.cpp` together in the concept folder simplifies everyday navigation and editing.
   - *When it becomes worth it:* When the project needs to be distributed or installed as a standalone C++ library with isolated public headers.
