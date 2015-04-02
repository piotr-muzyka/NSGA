#!/bin/bash

cd mathgl-2.3.2
cmake -D enable-all=on -D enable-all-widgets=on -D enable-all-swig=on -D enable-qt4=on .
cmake -D enable-all=on -D enable-all-widgets=on -D enable-all-swig=on -D enable-qt4=on  .
make

find . -type f -name 'libmgl*' -exec cp '{}' ../ ';'
