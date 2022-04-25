#!/bin/sh

GREEN='\e[1;32m'
RED='\e[1;31m'
NOCOLOR='\e[0m'

test_echo() {
    RESULT=$(bin/echo $2)
    if [ "$RESULT" = "$2" ]
    then
        echo -e "  * Example $1:$GREEN passed $NOCOLOR"
    else
        echo -e "  * Example $1:$RED failed $NOCOLOR"
        echo -e "    * Command \"echo $2\""
    fi
}

test_echo 1 "kaixo"
test_echo 2 "hello"
