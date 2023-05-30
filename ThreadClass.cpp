#include<stdio.h>
#include <pthread.h>
#include <unistd.h>

class ThreadClass
{
  
private:
    int count;
    pthread_t tp[10];
    pthread_t tc[10];
    pthread_mutex_t  MutexCount;
    static void * producer(void *arg);
    static void * consumer(void *arg);

public:
    ThreadClass();
    virtual ~ThreadClass();
    void StartThread();
    void Jointhread();
    void Display(){printf("%d\n",count);};
    void WorkingProducer();
    
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
        pthread_create(&tp[i],NULL,&producer,this);
        pthread_create(&tc[i],NULL,&consumer,this);

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
    //ThreadClass* mt = reinterpret_cast<ThreadClass*>(arg);
    ThreadClass* mt = (ThreadClass *) arg;
    mt->WorkingProducer();
    return 0;

}

void ThreadClass::WorkingProducer()
{
    pthread_mutex_lock(&MutexCount);
    count +=10;
    pthread_mutex_unlock(&MutexCount);
}

void * ThreadClass::consumer(void *arg)
{
    
}

int main()
{
    ThreadClass TC;
    TC.StartThread();
    TC.Display();
    TC.Jointhread();

    return 0;
}