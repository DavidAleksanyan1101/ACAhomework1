#include "king.hpp"
#include<iostream>

King::King(const std::string& color) : Figure( color , "King") {}

void King::move(int n , int m)
{


}

bool King::canMove(int n , int m)
{
    if (n >= 8 || m >= 8)
    {
        std::cout << "out of board" << std::endl;
        return false;
    }
    if (abs(getX() - n) <= 1 && abs(getY() - m) <= 1)
    {
        return true;
    }
}
