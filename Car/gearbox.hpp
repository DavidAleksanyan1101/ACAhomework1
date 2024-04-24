#ifndef __gearbox__
#define __gearbox__

#include<iostream>



class Gearbox
{
public:
    Gearbox() = default;
    Gearbox(const std::string& _type , const int& _gearsNumber);
public:
    void printInfo();


private:
    std::string gearboxType;
    int gearsNumber = 0;
};

#endif // __gearbox__