FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-24.04

# Use HTTPS mirrors to avoid campus/corporate firewall blocks on plain HTTP Ubuntu archives
RUN if [ -f /etc/apt/sources.list.d/ubuntu.sources ]; then \
        sed -i 's|http://archive.ubuntu.com/ubuntu|https://mirrors.edge.kernel.org/ubuntu|g; s|http://security.ubuntu.com/ubuntu|https://mirrors.edge.kernel.org/ubuntu|g' /etc/apt/sources.list.d/ubuntu.sources; \
    fi \
    && apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        cmake \
        ninja-build \
        make \
        build-essential \
        gdb \
        clang-format \
        clang-tidy \
    && apt-get clean && rm -rf /var/lib/apt/lists/*
