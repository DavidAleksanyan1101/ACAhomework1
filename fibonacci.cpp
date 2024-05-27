#include <iostream>

template<unsigned int T>
struct Fibonacci{
    static const long fib = Fibonacci<T - 1>::fib + Fibonacci<T - 2>::fib;
};

template<>
struct Fibonacci<0>{
    static const long fib = 0;
};

template<>
struct Fibonacci<1>{
    static const long fib = 1;
};


int main(){

    std::cout<<Fibonacci<17>::fib<<std::endl;

    return 0;
}