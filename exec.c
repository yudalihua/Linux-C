#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,const char* argv[])
{
  
   
    for(int i=0;i<8;++i)
    {
        printf("parent i=%d\n",i);
        
    }
      //create a child process
    pid_t pid=fork();
    if(pid==0)
    {
        int ret=execl("/bin/ls","666","-la",NULL);
        perror("error");
        exit(1);
    }
     for(int i=0;i<3;++i)
    {
        printf("parent i=%d\n",i);
        
    }
    

}


