#!/bin/bash

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${PROJECT_ROOT}/build"
CORES=$(nproc)

echo "VaultCLI Build"

# Setup build directory
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

# Configure if needed
if [ ! -f "CMakeCache.txt" ]; then
    echo "First time setup..."
    cmake .. -GNinja -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
fi

# Link compile_commands.json for clangd
ln -sf "${BUILD_DIR}/compile_commands.json" "${PROJECT_ROOT}/compile_commands.json"

# Generate .clangd config
cat > "${PROJECT_ROOT}/.clangd" << EOF
CompileFlags:
  Add: [-std=c++20]
Index:
  Background: Build
EOF

# Build
ninja -j$CORES

if [ $? -eq 0 ]; then
    echo ""
    echo "Build successful"
    echo "Client: ${BUILD_DIR}/client/vault_client"
    echo "Server: ${BUILD_DIR}/server/vault_server"
    echo ""
    echo "Intellisense configured"
else
    echo ""
    echo "Build failed"
    exit 1
fi