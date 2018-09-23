#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<string.h>
#include<sys/stat.h>
#include<sys/time.h>
#include<signal.h>
int main(int argc,const char* argv[])
{
    sigset_t  myset;
    sigemptyset(&myset);
    //customize my own set.
    sigaddset(&myset,SIGINT);
    sigaddset(&myset,SIGQUIT);
    sigaddset(&myset,SIGKILL);

    //pass my set to the blocked set of kernel.

    sigprocmask(SIG_BLOCK,&myset,NULL);
    
   while(1)
   {
       sigset_t pending_set;
       sleep(1);
       sigpending(&pending_set);
       for(int i=1;i<=32;++i)
       {
           if(sigismember(&pending_set,i))
           {
               printf("1\n");
            }
            else 
            {
                printf("0\n");

            }
                      
       }
    }
   
   return 0;
}
