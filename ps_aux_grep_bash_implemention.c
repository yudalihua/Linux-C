//implement "ps aux|grep bash" between parent and child process with c code 

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 

int main(int argc,const char* argv[])
{   
   
    int fd[2];
    int ret=pipe(fd);
    if(ret==-1)
    {
        perror("pipe error");
        exit(1);
    }
    //create a child porcess 
    pid_t pid=fork();
    if(pid==-1)
    {
        perror("fork error");
        exit(1);
    }
    //the parent process execute the command "ps aux".
    if(pid>0)
    {
        //the parent will write to the pipe ,so we'll close the read file descriptor.
        close(fd[0]);
        //redirect the stdout fd to the fd of pipe's write terminal.
        dup2(fd[1],STDOUT_FILENO);
        //execute the  "ps aux" command.
        execlp("ps","ps","aux",NULL);
        perror("execlp error");
        exit(1);

    }

    //the child process execute the command "grep bash"
    if (pid==0)
    {
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        execlp("grep","grep","bash","--color=auto",NULL);
   }
    

    
    
    return 0;


}
