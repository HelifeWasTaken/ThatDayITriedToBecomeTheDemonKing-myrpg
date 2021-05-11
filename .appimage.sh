#!/bin/bash

dir=$(dirname "$0")
host_dir="$PWD"

cd "$dir"
SAVE_FILE="$host_dir/save" ./my_rpg $@