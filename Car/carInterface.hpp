#ifndef __CarInterface__
#define __CarInterface__
#include<string>

class carInterface
{
public:
    virtual void printInfo()const = 0;
    virtual void printDetailedInfo()const = 0;
    virtual void setEngine(const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp) = 0;
    virtual void setGearbox(const std::string& gearType , const int& gears) = 0;
};


#endif //__CarInterface__