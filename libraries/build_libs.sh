#!/bin/bash

cd mathgl-2.3.2
cmake -D enable-qt4=on .
cmake -D enable-qt4=on .
make

find . -type f -name 'libmgl*' -exec cp '{}' ../ ';'
