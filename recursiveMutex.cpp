#include<iostream>
#include <pthread.h>


pthread_t t1[5];
pthread_mutex_t m1;
pthread_mutexattr_t attr1;


int count=0;
void * thread_routime(void * args)
{
    pthread_mutex_lock(&m1);
    pthread_mutex_lock(&m1);
    pthread_mutex_lock(&m1);
    std::cout << count++<<' ';
    pthread_mutex_unlock(&m1);
    pthread_mutex_unlock(&m1);
    pthread_mutex_unlock(&m1);


}
int main()
{
    
    pthread_mutexattr_init(&attr1);
    pthread_mutexattr_settype(&attr1,PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&m1,&attr1);
    for(int i=0;i<5;++i)
        pthread_create(&t1[i],0,&thread_routime,NULL);
    for(int i=0;i<5;++i)
        pthread_join(t1[i],NULL);
    pthread_mutex_destroy(&m1);
    pthread_mutexattr_destroy(&attr1);


    return 0;
}