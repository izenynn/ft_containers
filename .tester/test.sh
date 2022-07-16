#!/bin/bash

# compiler
CC="g++"
#CC="clang++"

# flags
CFLAGS=" -std=c++98 -Wall -Wextra -Werror -Wshadow -pedantic -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null"
#CFLAGS=" -std=c++98 -Wall -Wextra -Werror -Wshadow -pedantic -g3 -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null"
#CFLAGS=" -std=c++98 -Wall -Wextra -Werror -Wshadow -pedantic -g3"

# src
SRC_DIR="./srcs"
INC_DIR="./inc"

# includes
CFLAGS+=" -I ./inc"

# tester variables
LOG_DIR="./logs"

function test-cpp() {
	# $1 test container name
	# $2 test .cpp file name
	# $3 optional argument for test program

	if [[ -z $2 ]]; then
		echo "[ERROR]: function test-cpp(): not enought arguments provided"
		exit 1
	fi

	name="test.out"

	src="$SRC_DIR/$1/$2"
	
	std_log="std"".$1"".${2%.*}"".log"
	ft_log="ft"".$1"".${2%.*}"".log"
	diff_log="diff"".$1"".${2%.*}"".log"
	time_log="time"".$1"".${2%.*}"".log"
	
	echo -e "\n=============================================================="
	echo -e "\n>>> STARTING TESTS..."
	rm -rf ./"$LOG_DIR"
	mkdir ./"$LOG_DIR" 2> /dev/null
	
	echo -e "\n>>> RUNNING STL TESTS..."
	"$CC" $CFLAGS -o "$name" $src
	./"$name" $3 > "./$LOG_DIR/$std_log" 2>&1
	echo "STD:" > "./$LOG_DIR/$time_log"
	\time -p -a -o "./$LOG_DIR/$time_log" ./"$name" $3 > /dev/null 2>&1
	rm "$name"
	
	echo -e "\n>>> RUNNING FT TESTS..."
	"$CC" $CFLAGS -o "$name" -D "FT" $src
	./"$name" $3 > "./$LOG_DIR/$ft_log" 2>&1
	echo "FT:" >> "./$LOG_DIR/$time_log"
	\time -p -a -o "./$LOG_DIR/$time_log" ./"$name" $3 > /dev/null 2>&1
	rm "$name"
	
	echo -e "\n=============================================================="
	echo -e "\n>>> FUNCTIONALITY RESULTS"
	diff "./$LOG_DIR/$ft_log" "./$LOG_DIR/$std_log" 2> /dev/null > "./$LOG_DIR/$diff_log"
	cat "./$LOG_DIR/$diff_log"
	
	# test results
	if ! [[ -s ./$LOG_DIR/$diff_log ]]; then
		echo "✅ PERFECT! \\(^O^)/"
		ret="0"
	else
		regex=$(cat <<- EOF
^[0-9]*c[0-9]*
< max_size: [0-9]*
---
> max_size: [0-9]*$
EOF
)
	
		cat "./$LOG_DIR/$diff_log" | grep -v -E -q "$regex"
		res="$?"
		[ "$res" -eq "0" ] && (echo "❌ KO (T.T)"; ret="1") || (echo "⚠️ OK!  (^.^)"; ret="0")
	fi
	
	# time results
	echo -e "\n=============================================================="
	echo -e "\n>>> TIME RESULTS"
	#cat "./$LOG_DIR/$TIME_FILE"
}

function test-container() {
	# $1 container name
	# $@ .cpp files to test for this container
	argc=$#
	argv=("$@")

	if [[ -z $2 ]]; then
		echo "[ERROR]: function test-container(): not enought arguments provided"
		exit 1
	fi
	for (( j=1; j<argc; j++ )); do
		test-cpp $1 ${argv[j]}
	done
}

function main() {
	test-container general main.cpp
	exit 0
}

main
