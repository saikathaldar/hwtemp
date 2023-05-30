#include<iostream>
class Auotmobile{
private:
    int tyre;
    int chasis;
public:

    Auotmobile(int t, int c){tyre=t;chasis=c;};
    void display(){std::cout << tyre <<' '<< chasis<<' ';};

};

class Car : Auotmobile {
    private:
    int doors;
    public:

    Car(int t=100, int c=200, int d=400) : Auotmobile(t,c){doors=d;};
    void display(){std::cout << doors<<' ';Auotmobile::display();};

};
int main()
{
    Car vx(4,120,4);
    vx.display();
    Car vx1(8);
    vx1.display();

    return 0;
}