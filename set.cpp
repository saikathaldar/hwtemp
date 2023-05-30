#include <iostream>
#include <set>

int main()
{
    std::set<int> s_set;
    std::set<int>::iterator it;

    for(int i=0; i< 5;++i)
    {
        s_set.insert(i);
    }
    for(int i=0; i< 10;++i)
    {
        s_set.insert(i);
    }

    for(it=s_set.begin();it!=s_set.end();++it)
    {
        std::cout << *it <<std::endl;
    }

}