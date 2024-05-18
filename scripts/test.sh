#!/bin/bash 
set -euxo pipefail
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ctest --test-dir "$DIR"/../build-x86-Release -C Release -L "unit_tests" --output-on-failure
