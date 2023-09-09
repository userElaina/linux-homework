#!/bin/bash

read -p "input_n:" n
ps -eu | grep -v "PID" | awk '{print $3,$2}' | sort -r | head -n $n
read -p "input_pid:" ppid
function k(){
	for arg in $(ps --ppid $1 | grep -v "PID" | awk '{print $1}')
		do
			# echo "$arg of $1"
			k $arg
		done
	echo -e "kill $1"
}

k $ppid