#ifndef __parking__
#define __parking__
#include"car.hpp"


class Parking
{
public:
    Parking() = default;
    Parking(const int& _capacity , const int& _price);
    Parking(const Parking& p);
    ~Parking();
public:
    bool carIn(const Car& c);
    bool carOut(const Car& c);
    void getCarList();
    void getCarInfo(const int& carIndex);

private:
    int capacity = 0;
    int carCount = 0;
    int price = 0;
    const Car** parkingPlace = nullptr;
};


#endif // __parking__