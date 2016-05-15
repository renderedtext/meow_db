#!/usr/bin/env bash

mkdir -p build

gcc -Wall lib/*.c meow.c -I headers -o build/meow `pkg-config --cflags --libs glib-2.0`
