#!/bin/bash

set -e

config="$1"

case "$config" in
debug | release)
  ;;
*)
  echo "Invalid configuration: $config"
  echo "Choose either debug or release."
  exit 1
  ;;
esac

target="build/$config/compile_commands.json"
link="compile_commands.json"

if [[ ! -f "$target" ]]; then
  echo "Error: $target does not exist."
  exit 1
fi

if [[ -e "$link" && ! -L "$link" ]]; then
  echo "Error: $link already exists and is not a symlink."
  echo "Please move it or rename it."
  exit 1
fi

ln -sfn "$target" "$link"

echo "$link linked to $target"
