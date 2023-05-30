#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

void* roll_dice(void * arg)
{
    int *value;
    value = (int *) malloc(sizeof(int));

    *value = (rand() % 6)+1;
    printf("The value is = %d\n",*value);
    return (void *) value;
}



int  main(int agrc, char * argv[])
{
    int *res;
    srand(time(NULL));
    pthread_t thrd[4];   

    for (int i=0; i<4; ++i)
    {
        if( pthread_create(&thrd[i],NULL,&roll_dice,NULL) != 0)
        {
            return 1;
        }
    }
    for (int i=0; i<4; ++i)
    {    
         if(pthread_join(thrd[i],(void **) &res)!= 0)
        {
            return 3;
        }    
        printf("Randon number is=%d\n",*res);
    }
    
    
}