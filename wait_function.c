#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include<sys/types.h>

int main(int argc,const char* argv[])
{   
    pid_t pid=fork();
    if(pid>0)
    {
       int status;
       printf("parent process pid=%d,ppid=%d\n",getpid(),getppid());
       //the demonstration of wait function
       pid_t wpid= wait(&status);
       if(WIFEXITD(status))
       {
           //
           printf("exit value:%d\n",WEXITSTATUS(status));
       }
       //如果想要验证下边这个，那么就让子进程一直循环，然后用kill杀掉，观看结果。
       if(WIFSIGNALED(status))
       {
           //
           printf("exit by signal:%d\n",WTERMSIG(status));
       }
       
    }
    else if(pid==0)
    {
        sleep(2);
        printf("!!!!!!!!!!parent\n");
        printf("child pid=%d,ppid=%d\n",getpid(),getppid());

    }
    for(int i=0;i<5;++i)
    {
        printf("i=%d\n",i);
    }
    //both child and parent process exit with exit code of 9.
    return 9;


}
