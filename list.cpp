#include <iostream>
#include <list>
int main()
{
    std::list<int> l_list;
    std::list<int>::iterator it;

    for( int i; i<5;++i)
        l_list.push_back(i);

    it=l_list.begin();
    ++it;
    l_list.insert(it,777);


    for(it=l_list.begin(); it != l_list.end();++it)
    {
        std::cout << *it <<"   "<<std::endl;
    }
}