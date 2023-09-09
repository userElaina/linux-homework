#### killtool
First, input a number for how many head pids you want.
Second, input what pid you want to kill.

##### example
```c
# ./killtool.sh
09:40:01 up 0 min, 0 users, load average: 0.52, 0.58, 0.59
Input a number for how many head pids you want:
5
  PID %CPU COMMAND
  101 74.3 python3
   93 64.5 SCREEN -S p
  101 24.1 python3
   93 16.7 SCREEN -S q
    8  0.3 -bash
Please input what pid you want to kill:
93
The pid has children!
kill 101
kill 94
kill 93
```

##### source
```sh
s=`uptime`
echo $s
echo "Input a number for how many head pids you want:"
read N
let N=$N+1
ps -eo pid,%cpu,command --sort=-%cpu | head -$N

echo "Please input what pid you want to kill:" 
read pid

count=`ps --ppid $pid | wc -l`
if [ $count != 1 ];
then
    echo "The pid has children!"
else
    echo "The pid has no child!"
fi

function k(){
    for arg in $(ps --ppid $1 | grep -v "PID" | awk '{print $1}')
    do
        k $arg
    done
    echo -e "kill $1"
    kill $1
}
k $pid
```