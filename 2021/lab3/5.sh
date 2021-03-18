#!/bin/bash

current=0
echo "" > temp.txt
for current in $(ps -axo pid | grep -v [PID]) 
do
	ppid=$(cat /proc/$current/status 2>/dev/null | grep -E "PPid" | grep -Eo "[0-9]{1,}$")
	if [[ $ppid -eq "" ]]; then
		ppid="None"
	fi
	avg_time=$(cat /proc/$current/sched 2>/dev/null | grep -E "PPid" | grep -Eo "[0-9]{1,}$")
	sum_exec_runtime=$(cat /proc/$current/sched 2>/dev/null | grep -E "sum_exec_runtime"| grep -Eo "[0-9]{1,}.?([0-9]{1,})?$" | grep -Eo "^[0-9]{1,}")
	nr_switches=$(cat /proc/$current/sched 2>/dev/null | grep -E "nr_switches"| grep -Eo "[0-9]{1,}") 
	if  [[ $sum_exec_runtime -eq "" ]]  && [[ $nr_switches -eq "" ]];	then 
		avg_time=0
	else
	let avg_time=$sum_exec_runtime/$nr_switches;
	fi
	echo "ProcessID=$current : Parent_ProcessID=$ppid : Average_Time=$avg_time" >> temp.txt


done
sort temp.txt -b -k3 -g -t"=" > Out5.txt
