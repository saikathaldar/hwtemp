#include<iostream>
#include <algorithm>

int main()
{
    int sort_no[10]={5,3,6,7,9,6,8,95,54,34};  
    int ToAdd = 1;  
    

    std::sort(sort_no, sort_no + 9, [](int i, int j){if(i<j) return true; else return false;});

    std::for_each(sort_no, sort_no + 9, [ToAdd](int i){std::cout<< i + ToAdd << ' ';});
    
    return 0;
}