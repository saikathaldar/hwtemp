#include<iostream>
#include <thread>


void producer(int i)
{
    std::cout << "in thread procedure "<<i<<"\n";
}

class f1{
    public:
    void operator () (int i){
         std::cout << "in thread f1 "<<i<<"\n ";
    }
};

class sfx
{
private:
    /* data */
public:
   static void run(int i ){std::cout << "in thread sfx "<<i<<"\n ";}
};

class fx1
{
private:
    /* data */
public:
   void run(int i ){std::cout << "in thread fx1 "<<i<<"\n ";}
};



int main()
{
    std::thread t1(producer,10);
    std::thread t2([](int i){std::cout << "in thread lamda function "<<i<<"\n";},15);
    std::thread t3((f1()),11);
    std::thread t4(sfx::run,12);
    fx1 fx1i;
    std::thread t5(&fx1::run, fx1i, 14);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}