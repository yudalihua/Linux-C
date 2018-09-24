#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<string.h>
#include<sys/stat.h>
#include<pthread.h>
int number=100;
void* myfunc( void * arg)
{
    //print id of child threads.
    printf("id of child thread is %lu\n",pthread_self());
    for(int i=0;i<5;++i)
    {
        printf("child i=%d\n",i);
        if(i==2)
        {
            pthread_exit(&number);
        }
    }

}

int main(int argc,const char* argv[])
{
    //the value of the first argument will be passed from the function ,and pthid will save the id of pthread.
    pthread_t pthid;
    int ret=pthread_create(&pthid,NULL,myfunc,NULL);
    if(ret!=0)
    {
        printf("error number:%d\n",ret);
        printf("%s\n",strerror(ret));
    }
    printf("id of parent thread is %lu\n",pthread_self());
    //pthread_exit(NULL);  
    void * ptr=NULL;
    pthread_join(pthid,&ptr);
    printf("number=%d\n",*(int*)ptr);
    int i=0;
    while(i<7)
    {
        printf("parent i is %d\n",i);
        i++;
    }
   


    return 0;
}
