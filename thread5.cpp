#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


int mails=0;
pthread_mutex_t m1;

void* calculate(void * arg)
{
    //printf("Inside thread\n");

    for( int i=0 ; i< 10 ; ++i)
    {
       if(pthread_mutex_trylock(&m1) == 0)
       {
            printf("got lock %d\n",*(int *)arg);
            ++mails;
            sleep(1);
            pthread_mutex_unlock(&m1);
       }
        printf("didnt get lock %d\n",*(int *)arg);
    }
    //printf("exit thread\n");
}



int  main(int agrc, char * argv[])
{
    pthread_t thrd[4];
    
    pthread_mutex_init(&m1,NULL);

    int thread_no[4]={1,2,3,4};

    for (int i=0; i<4; ++i)
    {
        if( pthread_create(&thrd[i],NULL,&calculate,(void *)&thread_no[i]) != 0)
        {
            return 1;
        }
    }
    for (int i=0; i<4; ++i)
    {    
         if(pthread_join(thrd[i],NULL)!= 0)
        {
            return 3;
        }    
    }
    pthread_mutex_destroy(&m1);
    printf("no. of mails=%d\n",mails);
}