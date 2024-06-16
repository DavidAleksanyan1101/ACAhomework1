#include "../headers/knight.hpp"
#include "../../chessBoard.hpp"

Knight::Knight(const std::string &color) : Figure(color, "Knight") {}

bool Knight::canMove(int n, int m)
{
    if (n >= 8 || m >= 8 || n < 0 || m < 0)
    {
        throw std::out_of_range("invalid position");
    }
    if (n == getX() && m == getY())
    {
        return false;
    }
    if (abs(getX() - n) == 1 && abs(getY() - m) == 2)
    {
        return true;
    }
    else if (abs(getX() - n) == 2 && abs(getY() - m) == 1)
    {
        return true;
    }
}
