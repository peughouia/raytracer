# Contributing to Raytracer

Thank you for your interest in contributing! This document outlines our workflow and standards.

## 1. Branch Strategy and Pull Requests

- **Target Branch:** All pull requests must be submitted against the `dev` branch.
- **Main Branch:** Only project maintainers merge from `dev` to `main` upon release validation.
- **Commit Messages:** Follow the Conventional Commits specification:
  - `feat: <description>` for new capabilities
  - `fix: <description>` for bug fixes
  - `refactor: <description>` for structural improvements without functional changes
  - `test: <description>` for adding or updating tests
  - `docs: <description>` for documentation updates

## 2. Development Environment (Dev Containers)

We use Dev Containers to guarantee an identical toolchain across all platforms (see [docs/adr/0001-dev-container.md](file:///D:/MT5%20HETIC/raytracer/docs/adr/0001-dev-container.md)):
1. Install Docker Desktop and VS Code with the Dev Containers extension (or use container workflows in Zed).
2. Open this repository in VS Code.
3. Select **Reopen in Container** when prompted.

## 3. Build, Run, and Test Commands

Use the provided `Makefile` shortcuts (or standard `cmake` / `ctest` commands):
- `make` or `make build`: Configures and compiles the project and test suite.
- `make run`: Runs the raytracer demo binary.
- `make test`: Executes all unit tests via CTest (`ctest --test-dir build --output-on-failure`).
- `make clean`: Removes build output.

## 4. Test-Driven Development (TDD) Workflow

All additions and bug fixes must follow the **Red-Green-Refactor** cycle using Catch2 (see [docs/adr/0003-catch2.md](file:///D:/MT5%20HETIC/raytracer/docs/adr/0003-catch2.md)):
1. **Red:** Write a failing test in `tests/` describing the desired behavior.
2. **Green:** Implement the minimal code in `src/` to pass the test.
3. **Refactor:** Clean up and optimize the implementation while keeping all tests green.

## 5. Architectural Decisions (ADRs)

Our architecture decisions are documented in [docs/adr/](file:///D:/MT5%20HETIC/raytracer/docs/adr/):
- Consult existing ADRs before introducing new tools, libraries, or altering the build/test setup.
- Never violate an accepted ADR.
- To propose a new architectural direction or tool, draft a new ADR with status `Proposed` and open a PR against `dev` for review.
