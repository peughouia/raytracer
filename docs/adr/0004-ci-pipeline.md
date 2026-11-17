# 4. Use GitHub Actions with Dev Containers for Continuous Integration

## Context
To accept contributions safely, automated CI is required to build the project and execute test suites on every pull request. We considered alternatives such as GitLab CI, CircleCI, or running GitHub Actions directly on native virtual runner matrices (Ubuntu/Windows/macOS) without containers.

## Decision
We will use GitHub Actions executing our existing Dev Container configuration via the Dev Container CLI / GitHub Action. Every pull request targeting the `dev` branch will build the project and run `make test` (CTest with Catch2) within the exact same Ubuntu 24.04 environment used for local development.

## Status
Proposed

## Consequences
Continuous Integration guarantees strict parity with the local developer environment, eliminating "works in CI but fails locally" discrepancies.
However, building and spinning up the Docker container on hosted runners introduces initialization overhead and increases overall workflow execution times compared to bare-metal runners.
