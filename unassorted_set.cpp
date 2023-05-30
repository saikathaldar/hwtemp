#include <iostream>
#include <unordered_set>


int main()
{
    std::unordered_set<int> u_set;
    std::unordered_set<int>::iterator it;


    for(int i=10;i<20;++i)
    {
        u_set.insert(i);
    }
    u_set.insert(9);
    u_set.insert(99);
    u_set.insert(27);
    u_set.insert(55);
    u_set.insert(67);

    for(it=u_set.begin();it!=u_set.end();++it)
    {
        std::cout << *it << std::endl;
    }





}