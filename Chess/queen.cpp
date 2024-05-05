#include "queen.hpp"

Queen::Queen(const std::string& color) : Figure(color , "Queen") {}


bool Queen::canMove(int n , int m)
{
    if (n >= 8 || m >= 8)
    {
        std::cout << "out of board" << std::endl;
        return false;
    }
    if (getX() == n ^ getY() == m)
    {
        return true;
    }
    else  if (getX() + getY() == n + m)
    {
        return true;
    }
}
