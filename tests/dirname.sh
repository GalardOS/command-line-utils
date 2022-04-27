#!/bin/sh

GREEN='\e[1;32m'
RED='\e[1;31m'
NOCOLOR='\e[0m'

test_dirname() {
    RESULT=$(bin/dirname $2)
    if [ "$RESULT" = "$3" ]
    then 
        echo -e "  * Test $1:$GREEN passed $NOCOLOR"
    else
        echo -e "  * Test $1:$RED failed $NOCOLOR"
        echo -e "    * Command \"dirname $2\", expected result \"$3\""
    fi
}

test_dirname 1 "aa/bb" "aa"
test_dirname 2 "aa" "."
test_dirname 3 "aa/bb/cc" "aa/bb"
