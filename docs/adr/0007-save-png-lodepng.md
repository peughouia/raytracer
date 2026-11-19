# 7. Save Images as PNG using LodePNG

## Context

The client opens our images in ordinary viewers, so we save PNG. PNG is compressed and has checksums, so we use a library rather than write it ourselves.

The options we compared:
- **libpng**: the reference library, but a C API that takes many calls to save one image, and it isn't in our dev container.
- **stb_image_write**: a single header, public domain, but a C API with raw pointers, and larger PNG files.
- **LodePNG**: one .cpp and one .h, zlib licence, no dependencies, a C++ API with `std::vector`, but slower than the others at saving.
- **Writing PPM ourselves**: no library, but most viewers can't open it, and the files are far bigger.

## Decision

We will use LodePNG (from `https://github.com/lvandeve/lodepng`) to save images as PNG.
- It will be downloaded by CMake using `FetchContent` like Catch2.
- It will be pinned to commit `7b2893e35891c0c85bee5595caafaf3c2044b409` because the repository has no releases.
- Only `src/output/` will use it, behind our own interface `ImageSaver`, so that changing library or format means writing one new class.

## Status

Accepted

## Consequences

- Ordinary viewers can open our images out of the box.
- Files are compressed and have checksums.
- No manual dependency installation is required; CMake handles the download automatically via `FetchContent`.
- The codebase uses a clean C++ API with `std::vector` rather than raw C pointers.
- The rest of the codebase remains decoupled from LodePNG: swapping the library or format only requires implementing a new class for the `ImageSaver` interface.
- **Downsides:**
  - LodePNG is slower at saving images than the other libraries.
  - Pinning to a commit hash is required due to the lack of official release tags.
  - Fetching the dependency requires network access during the initial CMake configuration.
