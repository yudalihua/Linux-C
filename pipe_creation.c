//create a pipe 


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc,const char* argv[])
{
    int fd[2];
    int ret=pipe(fd);
    if(ret==-1)
    {
        perror("pipe error");
        exit(1);
    }
    printf("pipe[0]=%d\n",fd[0]);
    printf("pipe[1]=%d\n",fd[1]);
    close(fd[0]);
    close(fd[1]);   
    
    return 0;


}
