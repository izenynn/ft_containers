#!/bin/bash

if [[ -z $1 ]]; then
	echo "usage: $0 [0|1|2|3|4|5]"
	exit 1
fi

echo "=============================================================="
echo "COMPILING:"

#clang++ -std=c++98 -Wall -Wextra -Werror -Wshadow -pedantic -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null main"$1".cpp
#g++ -std=c++98 -Wall -Wextra -Werror -Wshadow -pedantic -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null main"$1".cpp

#clang++ -std=c++98 -Wall -Wextra -Werror -Wshadow -pedantic -g3 -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null main"$1".cpp

clang++ -std=c++98 -Wall -Wextra -Werror -Wshadow -pedantic -g3 main"$1".cpp

#clang++ -std=c++98 -g3 main"$1".cpp

echo "=============================================================="
echo "RUNNING:"

 ./a.out
