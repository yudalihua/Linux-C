#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<dirent.h>
#include<fcntl.h>

int main(void)
{
    int fd=open("test",O_RDWR|O_CREAT,0664);
    if(fd==-1)
    {
        perror("open error");
        exit(1);
    }
    int fd2=dup(fd);
    char *p="let coding change the world";
    write(fd2,p,strlen(p));
    close(fd2);

    char buf[1024];
    lseek(fd,0,SEEK_SET);
    read(fd,buf,sizeof(buf));
    printf("buf=%s\n",buf);
    close(fd);
    return 0;

}
  