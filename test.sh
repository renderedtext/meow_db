#!/usr/bin/env bash

rm -rf "build/test"
mkdir -p "build/test"

./build.sh
build/zen &

trap 'kill $(jobs -p)' EXIT

sleep 3

echo "================================="

for ctest in "test/*"
do
  echo "================================="
  echo "Running '$ctest'"
  echo "---------------------------------"

  g++ -Wall $ctest -o "build/test/current" && ./build/test/current

  exit_status=$?

  echo "---------------------------------"
  echo "Exit status: $exit_status"
  echo "================================="

  [[ $exit_status == 0 ]] || exit 1
done

exit 0
