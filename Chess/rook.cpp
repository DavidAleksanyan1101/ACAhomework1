#include "rook.hpp"

Rook::Rook(const std::string& color) : Figure( color , "Rook") {}

bool Rook::canMove(int n , int m)
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
    if (getX() == n ^ getY() == m)
    {
        return true;
    }
}
