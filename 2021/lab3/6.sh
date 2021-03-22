#!/bin/bash

FileIn=Out5.txt

ParentID=""
let time=0
let counter=0

while read LINE;do

ReadedParentID="$(echo $LINE | grep -Eo 'Parent_ProcessID\=[0-9]{1,}' | grep -Eo "[0-9]{1,}$" )";

#Пропускаем строки без Parent_ProcessID
if [[ "$ReadedParentID" -eq "" ]];then
continue;
fi

	if [[ $ParentID != $ReadedParentID ]] ;then
		if [[ "$counter" -eq "0" ]];then #Искл деление на 0
		echo -e "Average_Time_Children_of_ParentID=$ParentID is 0 \n$LINE"
		else 
		echo -e "Average_Time_Children_of_ParentID=$ParentID is $(echo $time/$counter | bc -l) \n$LINE"
		fi
		ParentID=$ReadedParentID
		let counter=0
		let time=0
	else
		echo "$LINE"
	fi

	added="$(echo $LINE | grep -Eo '[0-9]{1,}$')"
	let time=$time+$added
	let counter=$counter+1

done < $FileIn 

#
#while read LINE;do
#
#	echo "$LINE"
#
#done < $FileIn 
