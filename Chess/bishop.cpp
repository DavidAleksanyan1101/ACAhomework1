#include "bishop.hpp"

Bishop::Bishop(const std::string& color) : Figure( color , "Bishop") {}


bool Bishop::canMove(int n , int m)
{
    if (n >= 8 || m >= 8)
    {
        std::cout << "out of board" << std::endl;
        return false;
    }
    if (getX() + getY() == n + m || getX() - n == getY() - m)
    {
        return true;
    }
}
