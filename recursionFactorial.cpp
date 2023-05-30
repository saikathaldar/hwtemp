#include <iostream>

int factorial( int i);

int main()
{
    std::cout << factorial(10);
}


int factorial( int i)
{

if(i==0)
    return 1;
return i*factorial(i-1);


}