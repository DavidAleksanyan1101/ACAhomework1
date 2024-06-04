#include <iostream>

template<unsigned int T>
struct Fibonacci
{
    static const unsigned long long fib = Fibonacci<T - 1>::fib + Fibonacci<T - 2>::fib;
};

template<>
struct Fibonacci<0>
{
    static const  unsigned long long fib = 0;
};

template<>
struct Fibonacci<1>
{
    static const  unsigned long long fib = 1;
};

// int fib(int a)
// {
//     if (a == 0)return 0;
//     if (a == 1)return 1;
//     return fib(a - 1) + fib(a - 2);
// }

int main()
{

    std::cout << Fibonacci<901>::fib << std::endl;
    std::cout<<Fibonacci<899>::fib + Fibonacci<900>::fib<<std::endl;
    

    return 0;
}