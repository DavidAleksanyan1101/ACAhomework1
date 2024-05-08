#include <iostream>

class A
{
public:
    void operator()()
    {
        std::cout << "Called functor" << std::endl;
    }
    int operator()(int a , int b)
    {
        std::cout << "Called functor with 2 parameters , return add of integers" << std::endl;
        return a + b;
    }

};


int main()
{
    A a;
    a();
    a(5 ,6);

    return 0;
}