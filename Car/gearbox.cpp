#include"gearbox.hpp"

Gearbox::Gearbox(const std::string& _type , const int& _gearsNumber) : gearboxType(_type) , gearsNumber(_gearsNumber) {}

void Gearbox::printInfo()
{
    std::cout << "Gearbox type: " << gearboxType << std::endl;
    std::cout << "Gears number: " << gearsNumber << std::endl;
}