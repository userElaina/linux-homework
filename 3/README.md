### 全双工进程通信管道

通过 `fork()` 创建子进程,进程之间用 `pipe()` 通信.

##### 收发消息格式
```c
struct Msg{
    int count;
    int pid;
    char s[MAX];
};
```

##### 踩过的坑
```c
int _10[2],_01[2];
int _10p=pipe(_10);
int _01p=pipe(_01);
pid_t pid=fork();
if(pid==0)
{
    close(_01[0]);
    close(_10[1]);
    // write
}else if(pid>0){
    close(_01[1]);
    close(_10[0]);
    // read
}
```

```c
fflush(NULL);
```

##### 编译并运行
```sh
gcc 3.c -o 3 && ./3
```
##### 退出
以 `!` 开头的字符串.