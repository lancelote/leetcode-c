#!/usr/bin/env bash

set -euo pipefail
shopt -s nullglob

root_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source_dir="$root_dir/code"
build_dir="$root_dir/build"

mkdir -p "$build_dir"

pushd "$build_dir" > /dev/null
for source_file in "$source_dir"/*.c; do
    filename="$(basename "$source_file" .c)"
    clang -Wall -Wextra -Wstrict-prototypes -g "$source_file" -o "$build_dir/$filename"
done
popd > /dev/null
