#!/bin/sh

test_dirname() {
    RESULT=$(bin/dirname $2)
    if [ "$RESULT" = "$3" ]
    then 
        echo "  * Example $1: passed"
    else
        echo "  * Example $1: failed"
        echo "    * Command \"dirname $2\", expected result \"$3\""
    fi
}

test_dirname 1 "aa/bb" "aa"
test_dirname 2 "aa" "."
test_dirname 3 "aa/bb/cc" "aa/bb"
