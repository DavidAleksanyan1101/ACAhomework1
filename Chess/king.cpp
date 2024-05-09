#include "king.hpp"

King::King(const std::string& color) : Figure( color , "King") {}

bool King::canMove(int n , int m)
{
    if (n >= 8 || m >= 8)
    {
        std::cout << "out of board" << std::endl;
        return false;
    }
    if (n == getX() && m == getY())
    {
        return false;
    }
    if (abs(getX() - n) <= 1 && abs(getY() - m) <= 1)
    {
        return true;
    }
}
