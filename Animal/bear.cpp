#include "bear.hpp"

void Bear::voice()
{
    std::cout << "I am a bear!" << std::endl;
}

Bear::Bear(const std::string& name , const int& age) : Animal(name , age) {}