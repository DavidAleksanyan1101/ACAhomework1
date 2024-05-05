#include "knight.hpp"

Knight::Knight(const std::string& color) : Figure(color , "Knight") {}


bool Knight::canMove(int n , int m)
{
    if (n >= 8 || m >= 8)
    {
        std::cout << "out of board" << std::endl;
        return false;
    }
    if ( abs(getX() - n) == 1 && abs(getY() - m) == 2)
    {
        return true;
    }
    else  if ( abs(getX() - n) == 2 && abs(getY() - m) == 1)
    {
        return true;
    }
}
