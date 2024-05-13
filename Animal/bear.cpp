#include "bear.hpp"

void Bear::voice()
{
    std::cout << "I am a bear!" << std::endl;
}

Bear::Bear(const int& age) : Animal("Bear" , age) {}