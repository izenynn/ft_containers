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
TIME_FILE="time.log"

echo -e "\n=============================================================="
echo -e "\n>>> STARTING TESTS..."
rm -rf ./"$LOG_DIR"
mkdir ./"$LOG_DIR" 2> /dev/null

echo -e "\n>>> RUNNING STL TESTS..."
"$CC" $CFLAGS -o "$NAME" $SRC
./"$NAME" > "./$LOG_DIR/$STDLOG_FILE" 2>&1
echo "STD:" > "./$LOG_DIR/$TIME_FILE"
\time -p -a -o "./$LOG_DIR/$TIME_FILE" ./"$NAME" > /dev/null 2>&1
rm "$NAME"

echo -e "\n>>> RUNNING FT TESTS..."
"$CC" $CFLAGS -o "$NAME" -D "FT" $SRC
./"$NAME" > "./$LOG_DIR/$FTLOG_FILE" 2>&1
echo "FT:" >> "./$LOG_DIR/$TIME_FILE"
\time -p -a -o "./$LOG_DIR/$TIME_FILE" ./"$NAME" > /dev/null 2>&1
rm "$NAME"

echo -e "\n=============================================================="
echo -e "\n>>> FUNCTIONALITY RESULTS"
diff "./$LOG_DIR/$FTLOG_FILE" "./$LOG_DIR/$STDLOG_FILE" 2> /dev/null > "./$LOG_DIR/$DIFF_FILE"
cat "./$LOG_DIR/$DIFF_FILE"

# test results
if ! [[ -s ./$LOG_DIR/$DIFF_FILE ]]; then
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

	cat "./$LOG_DIR/$DIFF_FILE" | grep -v -E -q "$regex"
	res="$?"
	[ "$res" -eq "0" ] && (echo "❌ KO (T.T)"; ret="1") || (echo "⚠️ OK!  (^.^)"; ret="0")
fi

# time results
echo -e "\n=============================================================="
echo -e "\n>>> TIME RESULTS"
cat "./$LOG_DIR/$TIME_FILE"

# exit
exit "$ret"
