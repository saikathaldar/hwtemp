#include <iostream>

class BubbleShort
{
    private:
        int numbers[10];

    public:
        BubbleShort();
        void Init(int * x);
        void DoShort();
        void Display();
};

BubbleShort::BubbleShort()
{
    for(int i=0;i<10;++i)
        numbers[i]=0;
}

void BubbleShort::Init(int * x)
{
    for(int i=0;i<10;++i)
        numbers[i]=*(x+i);
}

void BubbleShort::DoShort()
{
    int temp,found;
    found=1;
    while(found)
    {
        found=0;
        for(int i=0;i<(10-1);++i)
        if(numbers[i]<numbers[i+1])
        {
            temp=numbers[i];
            numbers[i]=numbers[i+1];
            numbers[i+1]=temp;
            found=1;
        }
    }
}

void BubbleShort::Display()
{
    for(int i=0;i<10;++i)
        std::cout << numbers[i] << ' ';
    std::cout << std::endl;
}

int main()
{   
    BubbleShort BS;
    int x[]={2,3,6,2,9,6,5,7,8,56};
    BS.Init(x);
    BS.DoShort();
    BS.Display();


    BubbleShort *BSp = new BubbleShort();
    BSp->Init(x);
    BSp->DoShort();
    BSp->Display();

}