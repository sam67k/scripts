#!/bin/bash

function createDirectory() {
if [ -d $1 ]
then
echo -e "\nDirctories Exists!"
echo "Enter another Name Directory Already exists"
echo -n "Directory Name: "
read a
createDirectory $a
else
mkdir $1
fi
}

createDirectory $1
