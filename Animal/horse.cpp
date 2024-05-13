#include "horse.hpp"

void Horse::voice()
{
    std::cout << "I am a horse!" << std::endl;
}

Horse::Horse(const int& age) : Animal("Horse" , age) {}