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

## How We Work

- **TDD:** Write a failing test first, then only enough code to make it pass.
- **Expected Values:** Expected values come from the maths, not from running the code. If a test fails, ask me before changing what it expects.
- **Scope:** One small step at a time, only what I ask for.
- **Simplicity:** Keep the C++ simple: no advanced features unless I ask.
- **Host vs Container:** Don't build or run anything on the host: the commands run in the dev container.

## Contribution and Workflow Rules

- **Contribution Guide:** Follow all instructions in [CONTRIBUTING.md](file:///D:/MT5%20HETIC/raytracer/CONTRIBUTING.md).
- **Target Branch:** All pull requests and changes must target the `dev` branch. Only project owners merge `dev` into `main` after validation.
- **Commit Messages:** Must follow the Conventional Commits specification (`feat:`, `fix:`, `refactor:`, `test:`, `docs:`).
- **Code of Conduct:** Adhere to [CODE_OF_CONDUCT.md](file:///D:/MT5%20HETIC/raytracer/CODE_OF_CONDUCT.md).
- **License:** Project is licensed under the MIT License, see [LICENSE](file:///D:/MT5%20HETIC/raytracer/LICENSE).
- **Source Layout:** New classes go in the folder of their concept, and their tests in the matching folder under tests/.

## Coding Style Guidelines

- **Private Member Variables:** All private variables must have an underscore (`_`) prefix (e.g., `_x`, `_y`, `_z`).
- **No "get" Prefix:** Do not use the `get` prefix for accessor functions; it is redundant (e.g., use `x()`, `y()`, `z()` rather than `getX()`, `getY()`, `getZ()`).

## Architecture Decision Records (ADRs)

- Our architecture decisions are in `docs/adr/`: read them before changing the build, the tools, or the test setup.
- Never go against an accepted ADR: to change a decision, write a new ADR with status `Proposed` and ask me.
- Never set an ADR to `Accepted`.
