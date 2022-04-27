#!/bin/sh

GREEN='\e[1;32m'
RED='\e[1;31m'
NOCOLOR='\e[0m'

test_basename() {
    RESULT=$(bin/basename $2)
    if [ "$RESULT" = "$3" ]
    then 
        echo -e "  * Test $1:$GREEN passed $NOCOLOR"
    else
        echo -e "  * Test $1:$RED failed $NOCOLOR"
        echo -e "    * Command \"basename $2\", expected result \"$3\""
    fi
}

test_basename 1 "aa/bb" "bb"
test_basename 2 "aa" "aa"
test_basename 3 "aa/bb/cc" "cc"
test_basename 4 "aa/bb/cc.c .c" "cc"
test_basename 5 "aa/bb/cc .c" "cc"
