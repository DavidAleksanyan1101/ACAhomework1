#include "carSubclasses.hpp"

Sedan::Sedan(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year)
    : Car(_model , _color , _numberPlate , _year)
{
}
Sedan::Sedan(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears)
    : Car(_model , _color , _numberPlate , _year , _type , _cylinders , _volume , _hp , gearType , gears)
{
}

Coupe::Coupe(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year)
    : Car(_model , _color , _numberPlate , _year)
{
}
Coupe::Coupe(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears)
    : Car(_model , _color , _numberPlate , _year , _type , _cylinders , _volume , _hp , gearType , gears)
{
}

SUV::SUV(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year)
    : Car(_model , _color , _numberPlate , _year)
{
}
SUV::SUV(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears)
    : Car(_model , _color , _numberPlate , _year , _type , _cylinders , _volume , _hp , gearType , gears)
{
}

BMW::BMW(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year)
    : Sedan(_model , _color , _numberPlate , _year)
{
}

BMW::BMW(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears)
    : Sedan(_model , _color , _numberPlate , _year , _type , _cylinders , _volume , _hp , gearType , gears)
{
}

Toyota::Toyota(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year)
    : Sedan(_model , _color , _numberPlate , _year)
{
}

Toyota::Toyota(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears)
    : Sedan(_model , _color , _numberPlate , _year , _type , _cylinders , _volume , _hp , gearType , gears)
{
}

Cabriolet::Cabriolet(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year)
    : Coupe(_model , _color , _numberPlate , _year)
{
}

Cabriolet::Cabriolet(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears)
    : Coupe(_model , _color , _numberPlate , _year , _type , _cylinders , _volume , _hp , gearType , gears)
{
}

Crossover::Crossover(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year)
    : SUV(_model , _color , _numberPlate , _year)
{
}

Crossover::Crossover(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears)
    : SUV(_model , _color , _numberPlate , _year , _type , _cylinders , _volume , _hp , gearType , gears)
{
}







void Sedan::comfortModeEnable()
{
    std::cout << "Comfort mode enabled!" << std::endl;
    comfortMode = true;
}

void Sedan::comfortModeDisable()
{
    std::cout << "Comfort mode disabled!" << std::endl;
    comfortMode = false;
}

void Coupe::sportModeEnable()
{
    std::cout << "Sport mode enabled!" << std::endl;
    sportMode = true;
}
void Coupe::sportModeDisable()
{
    std::cout << "Sport mode Disabled!" << std::endl;
    sportMode = false;
}

void SUV::offRoadModeEnable()
{
    std::cout << "Offroad mode enabled!" << std::endl;
    offRoadMode = true;
}
void SUV::offRoadModeDisable()
{
    std::cout << "Offroad mode disabled!" << std::endl;
    offRoadMode = false;
}

void BMW::driftModeEnabled()
{
    comfortModeDisable();
    std::cout << "drift mode enabled" << std::endl;
    driftMode = true;
}
void BMW::driftModeDisabled()
{
    std::cout << "drift mode disabled" << std::endl;
    driftMode = false;
}

void Toyota::ecoModeEnabled(){
    std::cout<<"Eco mode enabled"<<std::endl;
    ecoMode = true;
}

void Toyota::ecoModeDisabled(){
    std::cout<<"Eco mode disabled"<<std::endl;
    ecoMode = false;
}

void Cabriolet::openRoof(){
    if (roofOpen == true)
    {
        std::cout<<"Roof is already opened"<<std::endl;
        return;
    }
    std::cout<<"Roof opened"<<std::endl;
    roofOpen = true;
}

void Cabriolet::closeRoof(){
    if (roofOpen == false)
    {
        std::cout<<"Roof is already closed"<<std::endl;
        return;
    }
    std::cout<<"Roof closed"<<std::endl;
    roofOpen = false;
}

void Crossover::comfortModeEnable()
{
    offRoadModeDisable();
    std::cout << "Comfort mode enabled!" << std::endl;
    comfortMode = true;
}

void Crossover::comfortModeDisable()
{
    std::cout << "Comfort mode disabled!" << std::endl;
    comfortMode = false;
}
