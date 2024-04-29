#include "cow.hpp"

void Cow::voice()
{
    std::cout << "I am a cow!" << std::endl;
}

Cow::Cow(const std::string& name ,const int& age) : Animal(name , age){}