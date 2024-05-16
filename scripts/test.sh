#!/bin/bash 
set -euxo pipefail
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ctest --test-dir "$DIR"/../build-x86-Debug --output-on-failure
ctest --test-dir "$DIR"/../build-x86-Release --output-on-failure
