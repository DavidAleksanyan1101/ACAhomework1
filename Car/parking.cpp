#include "parking.hpp"
#include<iostream>


Parking::Parking(const int& _capacity , const int& _price)
    : capacity(_capacity) , price(_price)
{
    parkingPlace = new const Car * [capacity];
    for (int i = 0; i < capacity; ++i)
    {
        parkingPlace[i] = nullptr;
    }
}

Parking::Parking(const Parking& p)
{
    capacity = p.capacity;
    price = p.price;
    parkingPlace = new const Car * [capacity];
    for (int i = 0; i < capacity; ++i)
    {
        parkingPlace[i] = nullptr;
    }
}

bool Parking::carIn(const Car& c)
{
    bool status = false;
    if (carCount == capacity)
    {
        std::cout << "All spaces is busy" << std::endl;
        return status;
    }
    for (int i = 0; i < capacity; ++i)
    {
        if (parkingPlace[i] == nullptr)
        {
            parkingPlace[i] = &c;
            carCount++;
            status = true;
            return status;
        }
    }
}

bool Parking::carOut(const Car& c)
{
    bool status = false;
    for (int i = 0; i < capacity; ++i)
    {
        if (parkingPlace[i] == &c)
        {
            parkingPlace[i] = nullptr;
            carCount--;
            status = true;
        }
    }
    return status;
}

void Parking::getCarList()
{
    if (carCount == 0)
    {
        std::cout << "0 cars in parking" << std::endl;
        return;
    }
    for (int i = 0; i < capacity; ++i)
    {
        if (parkingPlace[i] != nullptr)
        {
            parkingPlace[i]->printInfo();
            std::cout << std::endl;
        }
    }
}


