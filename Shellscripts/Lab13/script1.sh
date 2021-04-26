
#!/bin/bash

if [ $# == 0 ]
then
a=*
else
a=$1/*
fi

f=0
d=0
o=0

for i in $a
do
if [ -d $i ]
then
((d++))

elif [ -f $i ]
then
((f++))

else
((o++))
fi
done

echo -e "\nFiles: $f"
echo "Directories: $d"
echo -e "Others: $o\n"
