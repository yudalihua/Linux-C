#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter=200;
//create processes of brothers.only the father process can fork.
int main(int argc,const char* argv[])
{
    int number=3;
    int i=0;
    pid_t pid;
    for(i=0;i<number;++i)
    {
        pid=fork();
        if(pid==0)
        {
            break;
        }
    }
    //to determine the order of son process.
    if(i==0)
    {
        printf("first process,pid=%d\n",getpid());
        counter+=200;
        printf("counter=%d\n",counter);
    }
     if(i==1)
    {
        printf("second process,pid=%d\n",getpid());
        counter+=200;
        printf("counter=%d\n",counter);
    }
     if(i==2)
    {
        printf("third process,pid=%d\n",getpid());
        counter+=200;
        printf("counter=%d\n",counter);
    }
      if(i==3)
    {
        printf("parent process,pid=%d\n",getpid());
        counter+=300;
        printf("counter=%d\n",counter);
    }
    

}


