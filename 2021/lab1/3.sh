#!/bin/bash/


while read -r; do
	if [[ "$REPLY" == 'q' ]]
	then
	printf "%s\n" "$str"
	exit 0;
	fi
	str=$str$REPLY
	done 
 



