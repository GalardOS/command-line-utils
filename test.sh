#!/bin/sh

GREEN='\e[1;32m'
RED='\e[1;31m'
NOCOLOR='\e[0m'

clear
echo "---------------------------------------------------------------------------------"
echo " BUILD TEST"
echo "---------------------------------------------------------------------------------"
make > /dev/null 2> /dev/null
if [ $? = "0" ] 
then
    echo -e "* posix:$GREEN passed $NOCOLOR"
else
    echo -e "* posix:$RED failed $NOCOLOR"
    echo    "  * Could not build posix utilities, can't do further tests"
    exit 1
fi

# Prepare all the tests subdirs
cd tests
mkdir -p bin/
cp ../posix/bin/* ./bin

echo ""
echo "---------------------------------------------------------------------------------"
echo " POSIX UTILS TESTS"
echo "---------------------------------------------------------------------------------"

echo "* Basename"
sh basename.sh

echo ""
echo "* Dirname"
sh dirname.sh

echo ""
echo "* Echo"
sh echo.sh

echo ""
echo "* True"
sh true.sh
