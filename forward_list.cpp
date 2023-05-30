#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> f_list;
    std::forward_list<int>::iterator it;


    for(int i=0;i<10;++i)
        f_list.push_front(i);

    for(it=f_list.begin(); it!= f_list.end(); ++it)
    {
        std::cout << *it<< std::endl;
    }

}