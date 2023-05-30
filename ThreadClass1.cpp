#include<stdio.h>
#include <pthread.h>
#include <unistd.h>


class ThreadClass
{
private:
    private:
    static int count;
    pthread_t tp[10];
    pthread_t tc[10];
    static pthread_mutex_t  MutexCount;
    static void * producer(void *arg);
    static void * consumer(void *arg);
    public:
    
    ThreadClass();
    ~ThreadClass();
    void SetCount(int x){count=x;};
    void StartThread();
    void Jointhread();
    void Display(){printf("%d\n",count);};
    
};

ThreadClass::ThreadClass()
{

}

ThreadClass::~ThreadClass()
{
    
}

void ThreadClass::StartThread()
{
    pthread_mutex_init(&MutexCount,NULL);
     for(int i=0;i< 10;++i) 
    {
        pthread_create(&tp[i],NULL,&producer,NULL);
        pthread_create(&tc[i],NULL,&consumer,NULL);

    }
}
void ThreadClass::Jointhread()
{
    for(int i=0;i< 10;++i)
    {
        pthread_join(tp[i],NULL);
        pthread_join(tc[i],NULL);
    }
    pthread_mutex_destroy(&MutexCount);
}
void * ThreadClass::producer(void *arg)
{
    printf("Thread\n");
    pthread_mutex_lock(&MutexCount);
    count +=10;
    pthread_mutex_unlock(&MutexCount);

}

void * ThreadClass::consumer(void *arg)
{
    
}

int ThreadClass::count;
pthread_mutex_t  ThreadClass::MutexCount;

int main()
{
    //ThreadClass::count = 0;

    ThreadClass TC;
    TC.SetCount(0);
    TC.StartThread();
    TC.Display();
    TC.Jointhread();

    return 0;
}