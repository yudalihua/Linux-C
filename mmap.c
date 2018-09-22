//create a mmap region and read the content
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<string.h>
#include<sys/mman.h>
#include<fcntl.h>
int main(int argc,const char* argv[])
{  
    //open a file
    int fd=open("test",O_RDWR);
    int len=lseek(fd,0,SEEK_END);
   //create memory map region
   void *ptr=mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
   if(ptr==MAP_FAILED)
   {
       perror("mmap error");
       exit(1);
   }
   printf("%s",(char*)ptr);
   munmap(ptr,len);
   close(fd);

   return 0;













    return 0;


}
