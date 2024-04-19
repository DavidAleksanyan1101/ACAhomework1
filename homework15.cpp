#include<iostream>
#include<string>

class Car
{
public:
    std::string brand = "Tesla";
    std::string model = "Model S";
    std::string color = "white";
    std::string engineType = "Electric";
    int hp = 422; //horsepower
    int maxSpeed = 250;
    int year = 2017;
};

int main()
{
    Car car1;
    std::cout << car1.brand << " " << car1.model << " " << car1.year << std::endl;
    std::cout << "Color: " << car1.color << std::endl;
    std::cout << "Engine: " << car1.engineType << " " << car1.hp << "hp" << std::endl;
    std::cout << "Max speed " << car1.maxSpeed << "km/h" << std::endl;



    return 0;
}