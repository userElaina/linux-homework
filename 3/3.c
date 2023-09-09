#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#define MAX 1024
struct Msg{
    int count;
    int pid;
    char s[MAX];
};
int main()
{
    int _10[2],_01[2];
    int _10p=pipe(_10),_01p=pipe(_01);
    if(_10p==-1||_01p==-1){
        perror("pipe error\n");
        return -1;
    }
    pid_t pid=fork();
    if(pid==0)
    {
        int count=0;

        close(_01[0]);
        close(_10[1]);
        while(1)
        {
            count++;
            printf(">>> ");
            fflush(NULL);
            char s[MAX];
            fgets(s,sizeof(s),stdin);

            struct Msg*msg;
            msg=(struct Msg*)malloc(sizeof(struct Msg));
            msg->pid=pid;
            msg->count=count;

            strcpy(msg->s,"[");
            strcat(msg->s,s);
            int l=strlen(msg->s);
            msg->s[l-1]=']';
            msg->s[l]=0;

            write(_01[1],(char*)msg,sizeof(struct Msg));
            fflush(NULL);
            printf("pid=%d count=%d sendmsg='%s'\n",pid,count,msg->s);
            fflush(NULL);
            if(msg->s[1]=='!'){
                return 0;
            }

            ssize_t len=read(_10[0],(char*)msg,sizeof(struct Msg));
            // printf("pid=%d count=%d recvmsg='%s'\n",pid,count,msg->s);
        }
    }else if(pid>0){
        close(_01[1]);
        close(_10[0]);
        while(1){
            struct Msg*msg;
            msg=(struct Msg*)malloc(sizeof(struct Msg));
            ssize_t len=read(_01[0],(char*)msg,sizeof(struct Msg));
            printf("from=%d pid=%d count=%d recvmsg='%s'\n",msg->pid,pid,msg->count,msg->s);
            fflush(NULL);
            
            if(msg->s[1]=='!'){
                return 0;
            }

            strcpy(msg->s,"RECV");
            write(_10[1],(char*)msg,sizeof(struct Msg));
            fflush(NULL);
            // printf("pid=%d count=%d sendmsg='%s'\n",pid,msg->count,msg->s);
        }
    }else{
        perror("fork error\n");
        return -1;
    }
    return 0;
}