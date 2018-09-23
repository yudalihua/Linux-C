//we use the parent process's wait function to recycle child process and check the exit status.
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<string.h>
#include<signal.h>
#include<sys/wait.h>
int main(int argc,const char* argv[])
{  
    pid_t pid=fork();
    if(pid>0)
    {
        
           int s;
           pid_t wpid=wait(&s);
           printf(" child died with pid=%d\n",wpid);
           if(WIFSIGNALED(s))
           {
               printf("the child is killed by signal %d\n",WTERMSIG(s));

         
            }
    }
    else if(pid==0)
    {
        //ki
        sleep(2);
        raise(SIGINT);
        // abort();the abort() needs no argument and has no return value,it kill itself.
    }

   return 0;


}
