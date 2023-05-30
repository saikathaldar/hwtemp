#include <iostream>
#include <algorithm>>

void display(int i)
{
    std::cout << i<<' ';
}
int main()
{
    int accno[10]={5,3,77,54,97,44,753,34,67,34};


    for(int i=0;i<10;++i)
    {
        for(int j=i+1; j <10; ++j)
        {
            if(accno[i] > accno[j])
            {
                int temp = accno[i];
                accno[i] = accno[j];
                accno[j] = temp;
            }
        }
    }

    for(int i=0;i<10;++i)
        std::cout << accno[i] << ' ';
    
    std::cout << std::endl;

    for(int numb: accno)
        std::cout << numb << ' ';

    std::cout << std::endl;

    std::for_each(accno,accno+10,display);

    std::cout << std::endl;

    std::for_each(accno,accno+10,[](int ix) {std::cout << ix << ' ';}  );


}

