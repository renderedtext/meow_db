#!/usr/bin/env bash

mkdir -p build

gcc `pkg-config --cflags --libs glib-2.0` -Wall lib/*.c meow.c -I headers -o build/meow
