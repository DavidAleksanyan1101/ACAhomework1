#include "../headers/king.hpp"
#include "../../chessBoard.hpp"

King::King(const std::string &color) : Figure(color, "King") {}

bool King::canMove(int n, int m)
{
    if (n >= 8 || m >= 8 || n < 0 || m < 0)
    {
        throw std::out_of_range("invalid position");
    }
    if (n == getX() && m == getY())
    {
        return false;
    }
    if (abs(getX() - n) <= 1 && abs(getY() - m) <= 1)
    {
        if (board->positionStatus(n, m))
            return true;
    }
    return false;
}
