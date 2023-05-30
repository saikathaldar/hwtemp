#include<iostream>

class ComplexNumber
{
    int x,y;
    public:
    ComplexNumber();
    ComplexNumber(int x1,int y1);
    ComplexNumber  &operator + (ComplexNumber &CN);
    ComplexNumber &operator = (ComplexNumber &CN1);
    void display();
};

ComplexNumber  &ComplexNumber::operator + (ComplexNumber &CN)
{
    ComplexNumber *TCN = new ComplexNumber;
    TCN->x=x+CN.x;
    TCN->y=y+CN.y;
    return *TCN;
}
  ComplexNumber &ComplexNumber::operator = (ComplexNumber &CN1)
  {
    if(&CN1 == this) 
        return CN1;
    x = CN1.x;
    y = CN1.y;
    return *this;

  }

ComplexNumber::ComplexNumber(int x1,int y1)
{
    x=x1;
    y=y1;
}
ComplexNumber::ComplexNumber()
{
    x=0;y=0;
}
void ComplexNumber::display()
{
    std::cout << x << ' '<<y<<' '<<std::endl;
}

int main()
{
    ComplexNumber CP(2,5);
    CP.display();
    ComplexNumber CP1(4,6);
    CP1.display();

    ComplexNumber CP3;
    
    CP3 = CP + CP1;
    CP.display();
    CP1.display();
    CP3.display();

    ComplexNumber CP4;
    CP4 = CP;

    CP4.display();

    

    return 0;
}