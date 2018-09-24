#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<string.h>
#include<sys/stat.h>
#include<sys/time.h>
#include<signal.h>
void myfunc(int no)
    {
        printf("cath your signal%d\n",no);
       
    }


int main(int argc,const char* argv[])
{
    signal(SIGINT,myfunc);
    while(1)
    {
        printf("hello\n");
        sleep(1);
    }
    return 0;
}
