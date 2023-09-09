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
