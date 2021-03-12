#!/bin/bash/

numargs=$#

if((numargs!=2)) 
then 
echo -e 'Need enter only 2 words'
exit 0;
fi

var1=$1
var2=$2
if [ "$var1" == "$var2" ]
then
echo -e '\033[32m Equal\033[37m'
else
echo -e '\033[31m Diff\033[37m'
fi
