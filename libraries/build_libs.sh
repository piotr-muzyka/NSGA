#!/bin/bash

cd mathgl-2.3.2
cmake -D enable-all=on .
cmake -D enable-all=on .
make

find . -type f -name 'libmgl*' -exec cp '{}' ../ ';'
