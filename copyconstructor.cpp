#include <iostream>
#include <string.h>


class CustomerData{

private:
    char * name;
    int age;
public:
    CustomerData();
    CustomerData(CustomerData &p1);
    int getAge();
    char *getName();
    void putValue(int i, char * name);

};

CustomerData::CustomerData()
{
    age = 0;
    name = new char[20];    
}

int CustomerData::getAge()
{
    return age;

}
void CustomerData::putValue(int i, char * n1)
{
    age=i;
    strcpy(name,n1);
}
char *CustomerData::getName()
{
    return name;
}
CustomerData::CustomerData(CustomerData &p1)
{
    name = new char[20];
    strcpy(name,p1.name);
    age=p1.age;
}

int main()
{
    CustomerData CD;
    CD.putValue(50,"Saikat");
    std::cout << CD.getAge()<<' '<<CD.getName() << std::endl;

    CustomerData *CDnew = new CustomerData(CD);
    std::cout << CDnew->getAge()<<' '<<CDnew->getName() << std::endl;

    CD.putValue(50,"Tapesh");
    std::cout << CD.getAge()<<' '<<CD.getName() << std::endl;
    std::cout << CDnew->getAge()<<' '<<CDnew->getName() << std::endl;


}