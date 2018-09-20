#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,const char* argv[])
{   
    pid_t pid=fork();
    if(pid==0)
    {
        sleep(2);
        printf("child pid=%d,ppid=%d\n",getpid(),getppid());

    }
    else if(pid>0)
    {
        printf("!!!!!!!!!!parent\n");
        printf("parent pid=%d,ppid=%d\n",getpid(),getppid());
    }
    return 0;


}
