#!/bin/sh

clear
echo "---------------------------------------------------------------------------------"
echo " BUILD TEST"
echo "---------------------------------------------------------------------------------"
make > /dev/null 2> /dev/null
if [ $? = "0" ] 
then
    echo "* posix: passed"
else
    echo "* posix: failed"
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
