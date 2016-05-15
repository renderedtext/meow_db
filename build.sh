#!/usr/bin/env bash

mkdir -p build

gcc -Wall lib/*.c zen-server.c -I headers -o build/zen-server `pkg-config --cflags --libs glib-2.0`
