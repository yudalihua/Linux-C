//verify exit status of three child process.
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include<sys/types.h>

int main(int argc,const char* argv[])
{   
    int num=3;
    int i=0;
    pid_t pid;
    //let the parent process generate three child processes. don't let the child process generate child process.
    for(i=0;i<num;++i)
    {
        pid=fork();
        if(pid==0)
        {
            break;
        }
    }
    
    if(i==0)
    {
        execlp("ps","ps","aux",NULL);
        perror("execlp ps");
        exit(1);
    }
    else if(i==1)
    {
        execl("/root/scripts/today/process/app","app",NULL);
        perror("execl app");
        exit(1);
    }
    //execute an process of segment error
      else if(i==2)
    {
        execl("./error","error",NULL);
        perror("execlp error");
        exit(1);
    }
    else if(i==num)
    {
        int status;
        pid_t wpid;
        printf("now you are looking at parent process pid=%d\n",getpid());
        //上边的子进程死了，下边的wait函数才会被激活，收集死去的子进程的资源，然后返回死去的子进程的pid。
        while ((wpid=wait(&status))!=-1)
        {
            printf("----------child died pid=%d\n",wpid);
            if(WIFEXITED(status))
            {
                printf("return value %d\n",WEXITSTATUS(status));
            }
            else if(WIFSIGNALED(status))
            {
                printf("killed by signal :%d\n",WTERMSIG(status));

            }
            
        }

    }
return 0;


}
