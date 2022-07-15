#!/bin/bash

echo "=============================================================="
echo -e "\n>>> COMPILING"

NAME="test.out"

CC="g++"
#CC="clang++"

CFLAGS="-std=c++98 -Wall -Wextra -Werror -Wshadow -pedantic -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null"

#CFLAGS="-std=c++98 -Wall -Wextra -Werror -Wshadow -pedantic -g3 -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null"

#CFLAGS="-std=c++98 -Wall -Wextra -Werror -Wshadow -pedantic -g3"

SRC="main.cpp"

LOG_DIR="logs"
STDLOG_FILE="std.log"
FTLOG_FILE="ft.log"
DIFF_FILE="diff.log"

echo -e "\n=============================================================="
echo -e "\n>>> STARTING..."
rm -rf ./"$LOG_DIR"
mkdir ./"$LOG_DIR" 2> /dev/null

echo -e "\n>>> RUNNING STL"
"$CC" $CFLAGS -o "$NAME" $SRC
./"$NAME" > "./$LOG_DIR/$STDLOG_FILE" 2>&1
rm "$NAME"

echo -e "\n>>> RUNNING FT"
"$CC" $CFLAGS -o "$NAME" -D "FT" $SRC
./"$NAME" > "./$LOG_DIR/$FTLOG_FILE" 2>&1
rm "$NAME"

echo -e "\n=============================================================="
echo -e "\n>>> RESULTS"
diff "./$LOG_DIR/$FTLOG_FILE" "./$LOG_DIR/$STDLOG_FILE" 2> /dev/null > "./$LOG_DIR/$DIFF_FILE"
cat "./$LOG_DIR/$DIFF_FILE"

if ! [[ -s ./$LOG_DIR/$DIFF_FILE ]]; then
	echo -e "\n=============================================================="
	echo "✅ PERFECT! \\(^O^)/"
	echo -e "=============================================================="
	exit 0
fi
regex=$(cat <<- EOF
^[0-9]*c[0-9]*
< max_size: [0-9]*
---
> max_size: [0-9]*$
EOF
)

# finished
echo -e "\n=============================================================="
cat "./$LOG_DIR/$DIFF_FILE" | grep -v -E -q "$regex"
res="$?"
[ "$res" -eq "0" ] && echo "❌ KO (T.T)" || echo "⚠️  OK!  (^.^)"
echo -e "=============================================================="
[ "$res" -eq "0" ] && exit 1 || exit 0
