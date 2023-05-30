#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>


pthread_t t1[100];
pthread_mutex_t m1;
sem_t Login_queue;


void *LogIn(void * x)
{
    int i = *(int*)x;
    sem_wait(&Login_queue);
    std::cout<< "Logged in" << i <<std::endl;
    sleep(1);
    std::cout<< "Logged out" << i <<std::endl;   
    sem_post(&Login_queue);
}

int main()
{
    pthread_mutex_init(&m1,NULL);
    sem_init(&Login_queue,NULL,5);
    int index[100];
    for(int i=0;i<100;++i)
    {
        index[i] = i;
        pthread_create(&t1[i],NULL,&LogIn,&index[i]);
    }
   

    for(int i=0;i<100;++i)
        pthread_join(t1[i],NULL);
  


    sem_destroy(&Login_queue);
    pthread_mutex_destroy(&m1);
}
