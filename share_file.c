//investigate whether the parent process and the child process can share a regular file? the answer is yes.

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(int argc,const char* argv[])
{   
    int fd=open("temp",O_CREAT| O_RDWR,0664);
    if(fd==-1)
    {
        perror("open error");
        exit(1);
    }
    pid_t pid=fork();
    if(pid==-1)
    {
        perror("fork error");
        exit(1);
    }
    if(pid>0)
    {
        char *p="recently the microsoft is approaching";
        write(fd,p,strlen(p)+1);
        close(fd);
    }
    else if (pid==0)
    {
        //wait the parent process to write the string to the temp file.
        sleep(1);
        //assign a buffer 
        char buf[1024];
        lseek(fd,0,SEEK_SET);
        int len=read(fd,buf,sizeof(buf));
        printf("%s\n",buf);
        close(fd);

    }  
    return 0;


}
