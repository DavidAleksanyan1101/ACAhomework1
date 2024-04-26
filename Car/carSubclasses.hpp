#ifndef __carSubclasses__
#define __carSubclasses__

#include "car.hpp"

class Sedan : public Car
{
public:
    Sedan(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year);
    Sedan(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears);
public:
    void comfortModeEnable();
    void comfortModeDisable();
private:
    bool comfortMode = false;
};


class Coupe : public Car
{
public:
    Coupe(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year);
    Coupe(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears);

public:
    void sportModeEnable();
    void sportModeDisable();
private:
    bool sportMode = false;
};

class SUV : public Car
{
public:
    SUV(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year);
    SUV(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears);
public:
    void offRoadModeEnable();
    void offRoadModeDisable();
private:
    bool offRoadMode = false;
};


class BMW : public Sedan
{
public:
    BMW(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year);
    BMW(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears);
    void driftModeEnabled();
    void driftModeDisabled();
private:
    bool driftMode = false;
};

class Toyota : public Sedan
{
public:
    Toyota(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year);
    Toyota(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears);
    void ecoModeEnabled();
    void ecoModeDisabled();
private:
    bool ecoMode = false;
};
class Cabriolet : public Coupe
{
public:
    Cabriolet(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year);
    Cabriolet(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears);

    void openRoof();
    void closeRoof();
private:
    bool roofOpen = false;
};

class Crossover : public SUV
{
public:
    Crossover(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year);
    Crossover(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears);
public:
    void comfortModeEnable();
    void comfortModeDisable();
private:
    bool comfortMode = false;
};

#endif // __carSubclasses__