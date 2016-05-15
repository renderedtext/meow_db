#!/usr/bin/env bash

mkdir -p build

gcc -Wall lib/*.c zen.c -I headers -o build/zen `pkg-config --cflags --libs glib-2.0`
