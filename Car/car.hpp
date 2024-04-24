#ifndef __car__
#define __car__

#include "engine.hpp"
#include "gearbox.hpp"


class Car
{
public:
    Car() = default;
    Car(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year);
    Car(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears);
    Car(const Car& c);


public:
    void printInfo()const;
    void printDetailedInfo()const;

private:
    std::string model;
    std::string color;
    std::string numberPlate;
    int year = 0;
    Engine* engine = nullptr;
    Gearbox* gearbox = nullptr;
};


#endif // __car__