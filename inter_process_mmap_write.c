//create a mmap region and read the content
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<sys/mman.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,const char* argv[])
{  
    //open a file,because the original size of file is zero,so we need the ftruncate function to extend the file.
    int fd=open("temp",O_RDWR|O_CREAT,0664);
    int len=lseek(fd,0,SEEK_END);
   //create memory map region
   void *ptr=mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
   if(ptr==MAP_FAILED)
   {
       perror("mmap error");
       exit(1);
   }
   while(1)
   {
       char *p=(char*)ptr;
       p+=1024;
       strcpy(p,"hello world, i wll miss you\n ");
       sleep(2);
    }
   int ret=munmap(ptr,len);
   if(ret==-1)
   {
       perror("munmap error");
       exit(1);
   }


   return 0;


}
