#include "cat.hpp"

void Cat::voice()
{
    std::cout << "I am a cat!" << std::endl;
}

Cat::Cat(const int& age) : Animal("Cat" , age){}