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
	
	rm -rf ./"$LOG_DIR"
	mkdir ./"$LOG_DIR" 2> /dev/null
	
	# STD test
	"$CC" $CFLAGS -o "$name" $src
	./"$name" $3 > "./$LOG_DIR/$std_log" 2>&1
	#\time -p -a -o "./$LOG_DIR/$time_log" ./"$name" $3 > /dev/null 2>&1
	std_time=$(\time -f "%e" ./"$name" > /dev/null 2>&1) > /dev/null 2>&1
	rm "$name"
	
	# FT test
	"$CC" $CFLAGS -o "$name" -D "FT" $src
	./"$name" $3 > "./$LOG_DIR/$ft_log" 2>&1
	#\time -p -a -o "./$LOG_DIR/$time_log" ./"$name" $3 > /dev/null 2>&1
	#ft_time=$(\time -f "%e" ./"$name" > /dev/null 2>&1) 2>&1
	rm "$name"
	
	diff "./$LOG_DIR/$ft_log" "./$LOG_DIR/$std_log" 2> /dev/null > "./$LOG_DIR/$diff_log"
	#echo "std: $std_time | ft: $ft_time" > "./$LOG_DIR/$time_log"
	#time=$(cat "./$LOG_DIR/$time_log")
	
	# test results
	if ! [[ -s ./$LOG_DIR/$diff_log ]]; then
		emoji="✅"
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
		[ "$res" -eq "0" ] && emoji="❌" || emoji= "⚠️ ";
	fi

	# print results
	#echo "$emoji"" $time $1/${2%.*}"
	echo " $emoji | $1/${2%.*}"
}

function test-container() {
	# $1 container name
	# $@ .cpp files to test for this container

	echo -e "\n$1\n"

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

function test-bencharmk() {
	# $1 bencharmk name
	# $@ .cpp files to test

	echo -e "\n$1\n"

	argc=$#
	argv=("$@")
	if [[ -z $2 ]]; then
		echo "[ERROR]: function test-container(): not enought arguments provided"
		exit 1
	fi

	name="test.out"
	for (( j=1; j<argc; j++ )); do
		"$CC" $CFLAGS -o "$name" "./$SRC_DIR/$1/${argv[j]}"
		./"$name"
		rm "$name"
	done
}

function main() {
	echo "
##########################################################################
#   ___ __                         __         __                         #
# .'  _|  |_     .----.-----.-----|  |_.---.-|__.-----.-----.----.-----. #
# |   _|   _|    |  __|  _  |     |   _|  _  |  |     |  -__|   _|__ --| #
# |__| |_________|____|_____|__|__|____|___._|__|__|__|_____|__| |_____| #
#          |______|  __               __                                 #
#                   |  |_.-----.-----|  |_.-----.----.                   #
#                   |   _|  -__|__ --|   _|  -__|   _|                   #
#                   |____|_____|_____|____|_____|__|                     #
#                                                                        #
##########################################################################"

	# functionality checks
	test-container general main.cpp

	# bencharmk
	test-bencharmk benchmark benchmarks.cpp

	# exit
	exit 0
}

main
