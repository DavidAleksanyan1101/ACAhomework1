#include "engine.hpp"

Engine::Engine(const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp)
    : engineType(_type) , cylinderNumber(_cylinders) , volume(_volume) , hp(_hp)
{
}



void Engine::printInfo()
{
    std::cout << "Engine type: " << engineType << std::endl;
    std::cout << "Cylinder number: " << cylinderNumber << std::endl;
    std::cout << "Volume: " << volume << std::endl;
    std::cout << "Hp: " << hp << std::endl;
}