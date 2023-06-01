#include<iostream>
#include <queue>

int main()
{
    std::priority_queue<int> pq;

    int numbers[11]={3,7,0,7,56,8,9,6,5,7,5};

    for(int i=0;i< 11;++i)
    {
        pq.push(numbers[i]);
    }


    std::cout <<pq.top();

    return 0;
}