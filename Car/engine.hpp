#ifndef __engine__
#define __engine__
#include<iostream>

class Engine
{
public:
    Engine() = default;
    Engine(const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp);
public:
    void printInfo();


private:
    std::string engineType;
    int cylinderNumber = 0;
    int volume = 0;
    int hp = 0;
};

#endif // __engine__