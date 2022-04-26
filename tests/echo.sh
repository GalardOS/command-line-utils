#!/bin/sh

GREEN='\e[1;32m'
RED='\e[1;31m'
NOCOLOR='\e[0m'

test_echo() {
    RESULT=$(bin/echo $2)
    if [ "$RESULT" = $3 ]
    then
        echo -e "  * Test $1:$GREEN passed $NOCOLOR"
    else
        echo -e "  * Test $1:$RED failed $NOCOLOR"
        echo -e "    * Command \"echo $2\""
    fi
}

test_echo 1 "kaixo" "kaixo"
test_echo 2 "hello" "hello"

# TODO: multiline echo, CAN'T test right now because i don't really know how to add a newline character inside the script
