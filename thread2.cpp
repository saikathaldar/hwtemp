#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


int mails=0;
pthread_mutex_t m1;

void* calculate(void * arg)
{
    //printf("Inside thread\n");

    for( int i=0 ; i< 10000000 ; ++i)
    {
        pthread_mutex_lock(&m1);
        ++mails;
        pthread_mutex_unlock(&m1);
    }
    //printf("exit thread\n");
}



int  main(int agrc, char * argv[])
{
    pthread_t thrd[4];
    
    pthread_mutex_init(&m1,NULL);


    for (int i=0; i<4; ++i)
    {
        if( pthread_create(&thrd[i],NULL,&calculate,NULL) != 0)
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