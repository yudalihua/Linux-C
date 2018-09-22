//implement "ps aux|grep bash" between parent and child process with c code 

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<sys/wait.h> 
#include<fcntl.h>
#include<string.h>

int main(int argc,const char* argv[])
{  
    if(argc<2)
    {
        printf("./a.out fifoname\n");
        exit(1);
    }
    int ret=access(argv[1],F_OK);
    if(ret==-1)
    {
        int r =mkfifo(argv[1],0664);
        perror("mkfifo error");
        exit(1);
    }
    printf("the named pipe is created sucessfully");

    int fd=open("argv[1]",O_WRONLY);
    if(fd==-1)
    {
        perror("open error");
        exit(1);
    }
    char *p="hello world";
    whle(1)
    {
        sleep(1);
        int len=write(fd,p,strlen(p)+1);
    }
    close(fd);
    return 0;


}
