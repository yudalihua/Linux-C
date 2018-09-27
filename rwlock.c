#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<string.h>
#include<sys/stat.h>
#include<pthread.h>
//define a global variable.
int number=0;
pthread_rwlock_t lock;
void* write_func( void * arg)
{
    while(1)
    {
        //add a write lock.
        pthread_rwlock_wrlock(&lock);
        number++;
        printf("write:%lu",pthread_self(),number);
        //unlock the thread lock.
        pthread_rwlock_unlock(&lock);
        sleep(1);
    }  
    return NULL;

}

void* read_func( void * arg)
{
    while(1)
    {
        pthread_rwlock_rdlock(&lock);
        printf("read:%lu",pthread_self(),number);
        pthread_rwlock_unlock(&lock);
        sleep(1);
    }
   
    return NULL;

}

int main(int argc,const char* argv[])
{
    //initialize read/write lock.
    pthread_rwlock_init(&lock,NULL);
  
    pthread_t p[8];
    //create 3 write threads;
    for(int i=0;i<3;++i)
    {
        pthread_create(&p[i],NULL,write_func,NULL);
    }

    for(int i=3;i<8;++i)
    {
        pthread_create(&p[i],NULL,read_func,NULL);
    }
    //recycle the pcb of child threads.
    for(int i=0;i<8;++i)
    {
        pthread_join(p[i],NULL);
    }
    //release the lock.
    pthread_rwlock_destroy(&lock);
   
   


    return 0;
}
