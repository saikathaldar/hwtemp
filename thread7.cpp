#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


int fuel = 0;
pthread_mutex_t m1;
pthread_cond_t cond;

void* fuel_fill(void * arg)
{
    for (int i=0; i< 5; ++i)
    {
        pthread_mutex_lock(&m1);
        fuel += 60;
        pthread_mutex_unlock(&m1);
        pthread_cond_broadcast(&cond);
        printf("Tank Filled. fuel =%d\n",fuel);
        sleep(1);
    }
}

void* fill_car(void * arg)
{
   pthread_mutex_lock(&m1);
    while( fuel < 40)
    {
        printf("No fuel\n");
        sleep(1);
        pthread_cond_wait(&cond,&m1);
    }
    
    fuel -= 40;
    printf("Car Filled. fuel =%d\n",fuel);
    pthread_mutex_unlock(&m1);
}


int  main(int agrc, char * argv[])
{
    pthread_t thrd1, thrd2[4];
    
    pthread_mutex_init(&m1,NULL);
    pthread_cond_init(&cond,NULL);
        
    if( pthread_create(&thrd1,NULL,&fuel_fill,NULL) != 0)
    {
        return 1;
    }
    for(int  i=0; i < 4 ; ++i)
    {
        if( pthread_create(&thrd2[i],NULL,&fill_car,NULL) != 0)
        {
            return 1;
        }
    }
    if(pthread_join(thrd1,NULL)!= 0)
    {
        return 3;
    }    
    for(int  i=0; i < 4 ; ++i)
    {
        if(pthread_join(thrd2[i],NULL)!= 0)
        {
            return 3;
        }   
    }
    pthread_mutex_destroy(&m1);
    pthread_cond_destroy(&cond);
    
}