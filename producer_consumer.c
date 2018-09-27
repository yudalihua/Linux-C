//use the condition variable and mutex to realise the producer and consumer model.
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<string.h>
#include<sys/stat.h>
#include<pthread.h>


//create a  simple link list.
struct node
{
    int data;
    struct node * next;
}Node;

//define a pointer which always points to the head of linked list.
Node * head=NULL;
//define mutex and condition variable.
pthread_mutex_t mutex;
pthread_cond_t cond;

void* producer_func( void * arg)
{
    while(1)
    {
        //create a node of linked list.
        Node * pnew=(Node*)malloc(sizeof(Node));
        //initialize the node.
        pnew->data=rand()% 1000;

        //add a mutex
        pthread_mutex_lock(&mutex);
        pnew->next=head;
        //????
        head=pnew;
        printf("----producer:%lu,%d\n",pthread_self(),pnew->data);
        pthread_mutex_unlock(&mutex);
        
        //notify the consumer thread,and unblock it. the cond is the bridge of signal and wait functions' communication.
        pthread_cond_signal(&cond);
        sleep(rand()%3);
       
    }  
    return NULL;

}

void* consumer_func( void * arg)
{
    while(1)
    {
        pthread_mutex_lock(&lock);
        if(head==NULL)
        {
            //pass the cond and mutex,it can not only block the code, but after unlock the mutex.
            pthread_cond_wait(&cond.&mutex);
            //after the code is unblocked,the wait function can lock the mutex.
        }
        //if the link is not empty ,we need eat one node.
        Node* pdel=head;
        head=head->next;
        printf("-------deleted node %lu,%d\n",pthread_self(),pdel->data); 
        free(pdel);
        pthread_mutex_unlock(&lock);      
    }
   
    return NULL;

}

int main(int argc,const char* argv[])
{ 
    //initialization.
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);

    //create child threads.
    pthread_t p1,p2;
    pthread_create(p1,NULL,producer_func,NULL);
    pthread_create(p2,NULL,consumer_func,NULL);

    pthread_join(p1,NULL);
    pthread_join(p2,NULL);

    //destroy.
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);


    return 0;
}
