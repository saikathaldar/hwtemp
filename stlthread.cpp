#include<iostream>
#include <thread>


void producer(int i)
{
    std::cout << "in thread "<<i<<"\n";
}


int main()
{
    std::thread t1(producer,10);
    std::thread t2([](int i){std::cout << "in thread "<<i<<"\n";},10);

    t1.join();
    t2.join();

    return 0;
}