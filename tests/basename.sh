#!/bin/sh

test_basename() {
    RESULT=$(bin/basename $2)
    if [ "$RESULT" = "$3" ]
    then 
        echo "  * Example $1: passed"
    else
        echo "  * Example $1: failed"
        echo "    * Command \"basename $2\", expected result \"$3\""
    fi
}

test_basename 1 "aa/bb" "bb"
test_basename 2 "aa" "aa"
test_basename 3 "aa/bb/cc" "cc"
