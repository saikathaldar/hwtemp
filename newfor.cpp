#include <iostream>

int main()
{
    int list_no[]={1,2,3,4,5};
    for( auto i : list_no)
    {
        std::cout << i;
    }
}