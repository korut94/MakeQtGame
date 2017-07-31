#!/usr/bin/bash

# MakeQtGame
# Copyright (C) 2017 Andrea Mantovani
# Run the tests and clean the build directory

qmake
make check --silent
make clean
