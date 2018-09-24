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
        sleep(2);
        printf("wakeup\n");
    }


int main(int argc,const char* argv[])
{
    struct sigaction act;
    act.sa_flags=0;
    //clear the sa_mask
    sigemptyset(&act.sa_mask);
    //add mask signal to sa_mask temporarily.
    sigaddset(&act.sa_mask,SIGQUIT);
    act.sa_handler=myfunc;
    sigaction(SIGINT,&act,NULL);
    while(1);   
    return 0;
}
