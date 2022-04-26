#!/bin/sh

GREEN='\e[1;32m'
RED='\e[1;31m'
NOCOLOR='\e[0m'

bin/false

if [ "$?" != 0 ]
then
    echo -e "  * Test 1:$GREEN passed $NOCOLOR"
else
    echo -e "  * Test 1:$RED failed $NOCOLOR"
fi
