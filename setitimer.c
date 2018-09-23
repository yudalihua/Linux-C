//create a mmap region and read the content
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<string.h>
#include<sys/time.h>
int main(int argc,const char* argv[])
{  
    struct itimerval new_val;
    //set timer. the first time to invoke the alarm,then we can periodically invoke the alarm.
    //specify the seconds.
    new_val.it_value.tv_sec=2;
    //specify the microsecond
    new_val.it_value.tv_usec=0;

    //set periodic timer.
    new_val.it_interval.tv_sec=1;
    new_val.it_interval.tv_usec=0;

    setitimer(ITIMER_REAL,&new_val,NULL);
    while(1)
    {
        printf("hello world\n");
        sleep(1);
    }

   
   return 0;
}
