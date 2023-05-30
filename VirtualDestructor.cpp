#include<iostream>
class Auto{
    public:
    Auto(){std::cout << "Auto Constructor\n";};
    virtual ~Auto(){std::cout << "Auto Dectructor\n";};
};
class car : public Auto{
    public:
    car(){std::cout << "car Constructor\n";};
     ~car(){std::cout << "car Destructor\n";};

};
int main()
{
    Auto *a = new Auto;
    delete a;
    std::cout << "------------------\n";
    car *c = new car;
    delete c;
    std::cout << "------------------\n";
    Auto *a1 = new car;
    delete a1;
    return 0;
}