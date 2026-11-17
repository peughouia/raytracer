# Agent Guidelines

## Build, Run, and Test Commands

- **Configure & Build:**
  ```bash
  cmake -B build -S .
  cmake --build build
  ```
  *(or `make build`)*

- **Run:**
  ```bash
  ./build/bin/raytracer       # Linux / macOS
  .\build\bin\raytracer.exe   # Windows
  ```
  *(or `make run`)*

- **Test:**
  ```bash
  ctest --test-dir build --output-on-failure
  ```
  *(or `make test`, or direct binary `./build/bin/raytracer_tests`)*

## Architecture Decision Records (ADRs)

- Our architecture decisions are in `docs/adr/`: read them before changing the build, the tools, or the test setup.
- Never go against an accepted ADR: to change a decision, write a new ADR with status `Proposed` and ask me.
- Never set an ADR to `Accepted`.
