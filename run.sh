#!/bin/bash

set -e

#
# Prepare build directory
#
mkdir -p build
cd build

#
# Compile
#
cmake ../
make

#
# Run
#
./nintegration
