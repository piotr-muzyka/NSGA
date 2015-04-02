#!/bin/bash

cd mathgl-2.3.2
cmake -D enable-all-widgets=on enable-qt4=on enable-pthread=on .
cmake -D enable-all-widgets=on enable-qt4=on enable-pthread=on .
make

find . -type f -name 'libmgl*' -exec cp '{}' ../ ';'
