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
    pthread_t t1, t2;
    pthread_mutex_init(&m1,NULL);

    if( pthread_create(&t1,NULL,&calculate,NULL) != 0)
    {
        return 1;
    }

    if( pthread_create(&t2,NULL,&calculate,NULL) != 0)
    {
        return 2;
    }      
     if(pthread_join(t1,NULL)!= 0)
     {
        return 3;
     }
     if(pthread_join(t2,NULL)!= 0)
     {
        return 4;
     }
    pthread_mutex_destroy(&m1);
    printf("no. of mails=%d\n",mails);


}