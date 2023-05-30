#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int prime[] = {2,3,5,7,11,13,17,19,23,29};

void* prime_process(void * arg)
{
    int i =*(int*)arg;
    printf("The prime no is = %d index is = %d\n", prime[i],i);

}



int  main(int agrc, char * argv[])
{
 

    pthread_t thrd[10];   
    int index[10];
    for (int i=0; i<10; ++i)
    {
        index[i]=i;
        if( pthread_create(&thrd[i],NULL,&prime_process,&index[i]) != 0)
        {
            return 1;
        }
    }
    for (int i=0; i<10; ++i)
    {    
         if(pthread_join(thrd[i],NULL)!= 0)
        {
            return 3;
        }    
        
    }
    
    
}