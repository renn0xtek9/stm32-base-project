#!/bin/bash 
set -euxo pipefail
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$DIR"/../
cmake -S . -B build-x86-Release -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON --graphviz=build-x86-Release/cmake.dot
cmake -S . -B build-x86-Debug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_INSTALL_PREFIX=/usr/ --graphviz=build-x86-Debug/cmake.dot
