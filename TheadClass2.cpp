#include<iostream>
#include <time.h>
#include <unistd.h>

class TheadClass2
{
private:
    int count;
    
    pthread_mutex_t m;
public:
    
    static void * run(void * args);
    void ThreadFuncion();
    TheadClass2();
    virtual ~TheadClass2();
    void display(){};
};

TheadClass2::TheadClass2()
{
    pthread_mutex_init(&m,NULL);
}

TheadClass2::~TheadClass2()
{
    pthread_mutex_destroy(&m);
}

void *TheadClass2::run(void * args)
{
   TheadClass2 * TCO= (TheadClass2 *) args; 
    TCO->ThreadFuncion();
    
}
void TheadClass2::ThreadFuncion()
{
    pthread_mutex_lock(&m);
    ++count;
    pthread_mutex_unlock(&m);
}


int main()
{
    TheadClass2 TC;

    pthread_t t;

    pthread_create(&t,NULL,TheadClass2::run,&TC);

    //sleep(10);
    pthread_join(t,NULL);
    return 0;
}