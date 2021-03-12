#!/bin/bash/

counter=0
while read -r; do
	if [[ "$REPLY%2" -eq 0 ]]
	then
	echo $counter
	exit 0;
	else
	let "counter += 1"
	fi
	done 
 



