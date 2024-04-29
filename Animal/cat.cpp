#include "cat.hpp"

void Cat::voice()
{
    std::cout << "I am a cat!" << std::endl;
}

Cat::Cat(const std::string& name ,const int& age) : Animal(name , age){}