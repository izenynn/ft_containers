#!/bin/bash

if [[ -z $1 ]]; then
	echo "usage: $0 [1|2|3|4|5]"
	exit 1
fi

echo "=============================================================="
echo "COMPILING:"
 clang++ -std=c++98 -Wshadow -pedantic -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null main"$1".cpp
echo "=============================================================="
echo "RUNNING:"
 ./a.out
