#!/bin/sh

set -e

git submodule update --init --recursive

if [[ $# -ne 1 ]]; then
  echo "Typo!! Correct usage is ./build.sh <debug | release>"
  exit 1
fi

config="$1"

cmake -B build/debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build/debug -j${nproc}

cmake -B build/release -DCMAKE_BUILD_TYPE=Release
cmake --build build/release -j${nproc}

./scripts/compile_commands.sh "$config"
