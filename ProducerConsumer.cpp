#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>


pthread_t t1[2];
pthread_mutex_t m1;
sem_t Qfull,Qempty;

int jobs[10];
int count=0;
void Execute(int i)
{
    //execute jobs
    std::cout << "Executing Job "<<i << std::endl;
}
void *producer(void * arg)
{
    
    while(1)
    {
    
    sem_wait(&Qfull);
  
    pthread_mutex_lock(&m1);
    if(count < 10)
    {
        jobs[count]=(count*100)+100;
        ++count;
    }
    pthread_mutex_unlock(&m1);
    sem_post(&Qempty);
    
    }
}

void *consumer(void * arg)
{
    int x,found;
    
    while(1)
    {
        sem_wait(&Qempty);
        
         pthread_mutex_lock(&m1);
         found=0;
        if(count > 0)
        {
            x=jobs[count-1];
            --count;
            found=1;
        }
        pthread_mutex_unlock(&m1);
        sem_post(&Qfull);
        if(found)
            Execute(x);
    }
    
    
}



int main()
{
    pthread_mutex_init(&m1,NULL);
    sem_init(&Qfull,0,10);
    sem_init(&Qempty,0,0);
    pthread_create(&t1[0],NULL,&producer,NULL);
    pthread_create(&t1[1],NULL,&consumer,NULL);


    pthread_join(t1[0],NULL);
    pthread_join(t1[1],NULL);

    sem_destroy(&Qfull);
    sem_destroy(&Qempty);
    pthread_mutex_destroy(&m1);
}
