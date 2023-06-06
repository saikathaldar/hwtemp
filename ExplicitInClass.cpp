#include<iostream>
class ExplicitInClass
{
private:
    int x;
public:
    explicit ExplicitInClass(int i=5){x=5;};
    ~ExplicitInClass();
};


ExplicitInClass::~ExplicitInClass()
{
}

int main()
{
    ExplicitInClass ec(10);
    ExplicitInClass ec1=10; // this doesnt work
    return 0;
}