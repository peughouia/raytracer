# 6. One folder per concept

## Context

All our code sits in one flat `src/` folder, and all our tests in one flat `tests/` folder. That's fine for two or three classes, but a ray tracer will grow many: vectors, rays, shapes, materials, cameras, images. In one folder, they would be hard to tell apart, and it would not be clear which test file belongs to which class.

We want to find a class, and its tests, from its concept. We want to do this now, while there is only one class to move.

## Decision

Each concept gets its own folder under `src/`, holding its headers and sources. For example, `Vector` lives in `src/math/vector.h` and `src/math/vector.cpp`.

The tests mirror this layout: the tests for `src/math/vector.cpp` live in `tests/math/test_vector.cpp`.

Includes always start from `src/`, for example `#include "math/vector.h"`.

## Status

Accepted

## Consequences

- A class, and its tests, are found from the folder of their concept.
- An include line shows where a header comes from.
- Moving a file means changing the CMake lists, the includes that name it and the matching test.
- Someone has to decide which concept a class belongs to, and a folder with a single file can look like overkill at first.
- Nothing separates the public parts of a folder from its private parts.

## Left out for now

- **Namespaces**, such as `raytracer::Vector`. Worth it when two classes want the same name, or when other studios use our code inside theirs.
- **One library per folder.** Worth it when we want the build to stop one folder from depending on another, or when build times grow.
- **A separate `include/` folder** for public headers. Worth it when we ship the ray tracer as a library, and need to say which headers are public.
