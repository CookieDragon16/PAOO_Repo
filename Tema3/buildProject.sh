#!/bin/bash

while getopts "c" flag
do
    case "$flag" in
        c) 
            echo "Running clean build..."
            rm -rf build
            ;;
    esac
done

mkdir build
cd build
cmake ../src/

cmake --build .
