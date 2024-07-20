#!/bin/bash
set -euxo pipefail
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$DIR/.."
cmake --build build-x86-Debug --parallel "$(nproc)"
cmake --build build-x86-Release --parallel "$(nproc)"
