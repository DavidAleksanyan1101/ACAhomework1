#include "cow.hpp"

void Cow::voice()
{
    std::cout << "I am a cow!" << std::endl;
}

Cow::Cow(const int& age) : Animal("Cow" , age){}