#!/bin/bash 
set -euxo pipefail
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$DIR"/../build-x86-Release || exit 1
make package
