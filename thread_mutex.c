#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<string.h>
#include<sys/stat.h>
#include<pthread.h>
int MAX=10000;
//create a global mutex
pthread_mutex_t mutex;
int number;
//thread a function 
void* func_a( void * arg)
{
    for(int i=0;i<MAX;++i)
    {
        pthread_mutex_lock(&mutex);
        int cur=number;
        cur++;
        number=cur;
        printf("thread a ,id=%lu,number=%d\n",pthread_self(),number);
        pthread_mutex_unlock(&mutex);
          
    }
    return NULL;

}
//thread b function
void* func_b( void * arg)
{
    for(int i=0;i<MAX;++i)
    {
        pthread_mutex_lock(&mutex);
        int cur=number;
        cur++;
        number=cur;
        printf("thread b ,id=%lu,number=%d\n",pthread_self(),number);
        pthread_mutex_unlock(&mutex);
       
     
    }
    return NULL;

}

int main(int argc,const char* argv[])
{
    pthread_t p1,p2;
    //initialize the pthread mutex.
    pthread_mutex_init(&mutex,NULL);
    
    //create two child threads.
    pthread_create(&p1,NULL,func_a,NULL);
    pthread_create(&p2,NULL,func_b,NULL);
    
    //get blocked,and wati to recycle the threads resources.
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);  
   
   
    //destroy the mutex resource.
    pthread_mutex_destroy(&mutex);
    return 0;
}
