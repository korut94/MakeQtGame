#!/bin/bash

# MakeQtGame
# Copyright (C) 2017 Andrea Mantovani
# Run the tests and clean the build directory if all of them are passed
# succesfully.

set -e

qmake
make check --silent
make clean --silent
