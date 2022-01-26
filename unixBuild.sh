#!/bin/bash

mkdir -p build
cd build
cmake -S ../ -B . -DCMAKE_TOOLCHAIN_FILE=/Users/gharlock/vcpkg/scripts/buildsystems/vcpkg.cmake
make && make Shaders && ./VulkanApp
cd ..