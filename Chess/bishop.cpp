#include "bishop.hpp"
#include "chessBoard.hpp"

Bishop::Bishop(const std::string& color) : Figure(color , "Bishop") {}

bool Bishop::canMove(int n , int m)
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

    if (getX() - n == getY() - m)
    {
        if (getX() < n)
        {
            for (int i = 1; i < n - getX(); ++i)
            {
                if (!(board->positionStatus(getX() + i , getY() + i)))
                {
                    return false;
                }
            }
            return true;
        }
        if (getX() > n)
        {
            for (int i = 1; i < getX() - n; ++i)
            {
                if (!(board->positionStatus(n + i , m + i)))
                {
                    return false;
                }
            }
            return true;
        }
    }
    else if (getX() + getY() == n + m)
    {
        if (getX() < n)
        {
            for (int i = 1; i < n - getX(); ++i)
            {
                if (!(board->positionStatus(getX() + i , getY() - i)))
                {
                    return false;
                }
            }
            return true;
        }
        if (getX() > n)
        {
            for (int i = 1; i < getX() - n; ++i)
            {
                if (!(board->positionStatus(n - i , m + i)))
                {
                    return false;
                }
            }
            return true;
        }
    }
}
