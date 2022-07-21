#!/bin/bash

# compiler
CC="g++"
#CC="clang++"

# flags
CFLAGS=" -std=c++98 -Wall -Wextra -Werror -Wshadow -pedantic"
#CFLAGS+=" -g3 -fsanitize=address"
CFLAGS+=" -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null"

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

	std_name="std.elf"
	ft_name="ft.elf"

	src="$SRC_DIR/$1/$2"
	
	std_log="std"".$1"".${2%.*}"".log"
	ft_log="ft"".$1"".${2%.*}"".log"
	diff_log="diff"".$1"".${2%.*}"".log"
	time_log="time"".$1"".${2%.*}"".log"
		
	# compile and run
	"$CC" $CFLAGS -o "$std_name" $src
	"$CC" $CFLAGS -o "$ft_name" -D "FT" $src

	./"$std_name" $3 > "./$LOG_DIR/$std_log" 2>&1
	./"$ft_name" $3 > "./$LOG_DIR/$ft_log" 2>&1

	rm "$std_name"
	rm "$ft_name"
	
	diff "./$LOG_DIR/$ft_log" "./$LOG_DIR/$std_log" 2> /dev/null > "./$LOG_DIR/$diff_log"
	
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
		[ "$res" -eq "0" ] && emoji="❌" || emoji="⚠️"
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

	name="bench.elf"
	for (( j=1; j<argc; j++ )); do
		"$CC" $CFLAGS "-O3" -o "$name" "./$SRC_DIR/$1/${argv[j]}"
		#"$CC" $CFLAGS -o "$name" "./$SRC_DIR/$1/${argv[j]}"
		./"$name"
		rm "$name"
	done
}

function main() {
	rm -rf ./"$LOG_DIR"
	mkdir ./"$LOG_DIR" 2> /dev/null

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

	# functionality tests
	test-container general \
		main.cpp

	test-container stack \
		ctorz.cpp			push.cpp			push_pop.cpp		copy_ctorz.cpp		\
		assign_optr.cpp		list_ctorz.cpp		relt_optr.cpp		list_relt_optr.cpp	\


	test-container vector \
		ctorz.cpp			copy_ctorz.cpp		assign_optr.cpp		assign.cpp			\
		at.cpp				front_back.cpp		insert.cpp			erase.cpp			\
		push_pop.cpp		resize.cpp			reserve.cpp			swap.cpp			\
		ite.cpp				ite_optr.cpp		ite_relt_optr.cpp	rite.cpp			\
		rite_optr.cpp		rite_relt_optr.cpp	relt_optr.cpp

	test-container map \
		ctorz.cpp			insert.cpp			copy_ctorz.cpp		assign_optr.cpp		\
		sqbr_optr.cpp		erase.cpp			"clear.cpp"			"find.cpp"			\
		count.cpp			swap.cpp			relt_optr.cpp		ite.cpp				\
		ite_optr.cpp		rite.cpp			rite_optr.cpp		compare.cpp

	test-container "set" \
		ctorz.cpp			insert.cpp			copy_ctorz.cpp		assign_optr.cpp		\
		erase.cpp			"clear.cpp"			"find.cpp"			count.cpp			\
		swap.cpp			relt_optr.cpp		ite.cpp				ite_optr.cpp		\
		rite.cpp			rite_optr.cpp		compare.cpp

	# bencharmk
	test-bencharmk benchmark benchmark.cpp

	# exit
	exit 0
}

main
