# 1. Use Dev Containers for Development Environment

## Context
Contributors work across different operating systems (Windows, macOS, and Linux) with varying compiler versions and toolchains. We considered alternatives such as requiring developers to manually install tools on their host operating system, or using full virtual machines (VMs).

## Decision
We will use Dev Containers (Docker) to provide the development environment. This enables the project to run on all platforms and gives every contributor an identical, pre-configured toolchain.

## Status
Proposed

## Consequences
The development environment is consistent across all platforms with zero manual dependency installation.
However, developers must have Docker Desktop or an equivalent container runtime installed and running, which adds memory, disk, and CPU overhead.
