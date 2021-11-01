#### Menu

具有子菜单、返回上一层、退出功能的菜单.
通过配置配置文件 `2.conf` 生成需要的菜单,配置文件中以 `#` 开头的为注释.
通过动态生成正则表达式实时提取菜单.

##### conf-example
```sh
1 MENU1: apt and pip
1.1 apt
1.1.1 update
1.1.1.0 apt update
1.1.2 install
1.1.2.1 unzip
1.1.2.1.0 apt install unzip
1.1.2.2 screen
1.1.2.2.0 apt install screen
1.1.2.3 python3
1.1.2.3.0 apt install python3
1.1.2.4 python3-pip
1.1.2.4.0 apt install python3-pip
1.2 pip
1.2.1 install
1.2.1.1 requests
1.2.1.1.0 pip3 install requests
1.2.2 upgrade
1.2.2.1 requests
1.2.2.1.0 pip3 install --upgrade requests
1.2.2.2 pip
1.2.2.2.0 pip3 install --upgrade pip
2 MENU2: other
2.1 pwd
2.1.0 pwd
2.2 w
2.2.0 w
2.3 ls
2.3.0 ls -alh
2.4 whoami
2.4.0 whoami
2.5 killtool
2.5.0 ../1/killtool.sh
# -1 back
# -2 exit
```

##### source
```sh
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
```