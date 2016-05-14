#!/usr/bin/env bash

mkdir -p build

g++ -Wall lib/*.c meow.c -I headers -o build/meow

g++ -Wall test_client.c -o build/test_client
