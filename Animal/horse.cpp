#include "horse.hpp"

void Horse::voice()
{
    std::cout << "I am a horse!" << std::endl;
}

Horse::Horse(const std::string& name , const int& age) : Animal(name , age) {}