#!/bin/bash

rm -rf build
mkdir build
cd build
cmake ..
make
./sdl3-snake
