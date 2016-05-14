#!/usr/bin/env bash

mkdir -p build

# g++ -Wall meow.c -o build/meow
g++ -Wall test_client.c -o build/test_client
