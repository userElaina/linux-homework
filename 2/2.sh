#!/bin/bash

pth=$(dirname $(readlink -f $0))"/2.conf"

function f(){
    str=""
    str2=""
    fa=""
    fa2=""
    flg=0
    for arg in $*
    do
        if test $flg -eq 0;then
            fa=$arg" "
            str=$arg"\."
            flg=1
            continue
        fi
        str2=$str
        str=$str$arg"\."
        fa2=$fa
        fa=$fa$arg" "
    done

    str="^"$str

    str2=$str"0"
    `cat $pth | grep --color=never -vP '^#' | grep --color=never -P "$str2" | awk '{print $2}'`

    str=$str"[1-9][0-9]*[\s]"
    # echo "REGEX2: "$str
    cat $pth | grep --color=never -vP '^#' | grep --color=never -P $str | awk -F. '{print $NF}'
    echo "-1 back"
    echo "-2 exit"

    read -p ">>> " n
    if test $n -eq -2;then
        exit 0
    fi
    if test $n -eq -1;then
        f $fa2
    else
        f $* $n
    fi
}

f
