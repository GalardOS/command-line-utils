#!/bin/sh

echo "---------------------------------------------------------------------------------"
echo " BUILD TEST"
echo "---------------------------------------------------------------------------------"
make > /dev/null 2> /dev/null
if [ $? = "0" ] 
then
    echo "* posix: passed"
else
    echo "* posix: failed"
fi

