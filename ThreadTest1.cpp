#include <stdio.h>
#include <pthread.h>
#include <time.h>

#include <unistd.h>


int tank=0;
pthread_t t1[5],t2[5];
pthread_mutex_t m1;
pthread_cond_t c1;

void* routine(void * args)
{
    while(1)
    {
        pthread_mutex_lock(&m1);
            tank+=10;
        printf("Tank Filled 10\n");
        pthread_mutex_unlock(&m1);
        pthread_cond_signal(&c1);
    }
}

void *routine1(void * args)
{
    while(1)
    {
        pthread_mutex_lock(&m1);
        while(tank < 40)
        {
            sleep(1);
            pthread_cond_wait(&c1,&m1);  
        }
        tank-=40;
        printf("Tank Emptyed 40\n");
        pthread_mutex_unlock(&m1);
    }

}
int main()
{
    pthread_mutex_init(&m1,NULL);
    pthread_cond_init(&c1,NULL);

    for(int i=0; i<5;++i)
        pthread_create(&t1[i],NULL,&routine,NULL);

    for(int i=0; i<5;++i)
        pthread_create(&t2[i],NULL,&routine1,NULL);
    
    for(int i=0; i<5;++i)
        pthread_join(t1[i],0);
    
    for(int i=0; i<5;++i)
        pthread_join(t2[i],0);

    printf("%d ",tank);
    
    pthread_cond_destroy(&c1);
    pthread_mutex_destroy(&m1);
}

