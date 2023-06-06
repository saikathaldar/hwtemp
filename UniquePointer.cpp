#include<iostream>
#include <memory>

class calc 
{
    int x,y;
public:
    explicit calc(int x1, int y1) : x{x1},y{y1} {};
    int add () {return x+y;}; 
    ~calc(){std::cout<<"dest called";};
};

int main()
{
    calc c(1,2);

    
    
    std::unique_ptr<calc> q = std::make_unique<calc>(1,2); 
    std::cout << " the sum is " << q->add() << std::endl;
    std::unique_ptr<int> uptr = std::make_unique<int>(25);
    std::cout << *uptr << std::endl;

    std::shared_ptr<int> sptr = std::make_shared<int>(55);
    std::cout << *sptr << std::endl;

    std::shared_ptr<int> sptr1 = sptr;
    std::cout << *sptr1 << std::endl;

    std::cout << sptr.use_count() << std::endl;
    std::cout << sptr1.use_count() << std::endl;

    std::weak_ptr<int> wptr=sptr;
    std::cout << *(wptr.lock()) << std::endl;

    std::cout << wptr.use_count() << std::endl;
    std::cout << sptr.use_count() << std::endl;
    return 0;
}


