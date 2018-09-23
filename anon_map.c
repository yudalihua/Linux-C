#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<string.h>
#include<sys/mman.h>
#include<fcntl.h>
int main(int argc,const char* argv[])
{  
    //designate the size of the map region
    int len=4096;
   //create anonmous memory map region,we need MAP_ANON,and do not need the fd,so we pass -1 to fd.
   void *ptr=mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);
   if(ptr==MAP_FAILED)
   {
       perror("mmap error");
       exit(1);
   }
    
    //create a child process.the child can access the map by the ptr.
    pid_t pid =fork();
    if(pid==-1)
    {
        perror("fork error");
        exit(1);
    }
    else if(pid>0)
    {   
        //write the data to the map. the string "can you find me" will override the same long bytes in the file. 
        strcpy((char*)ptr,"can you find me");
        wait(NULL);
    }
    else if(pid==0)
    {
        //when the printf meet the ^@,it will stop.
        printf("%s\n",(char*)ptr);
    }
    //release the memory of map region
    int ret=munmap(ptr,len);
    if(ret==-1_
    {
        perror("munmap error");
        exit(1);
    })
   return 0;
}
