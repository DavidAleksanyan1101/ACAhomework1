#include "../headers/rook.hpp"
#include "../../chessBoard.hpp"

Rook::Rook(const std::string& color) : Figure(color , "Rook") {}

bool Rook::canMove(int n , int m)
{
    if (n >= 8 || m >= 8 || n < 0 || m < 0)
    {
        throw std::out_of_range("invalid position");
    }
    if (n == getX() && m == getY())
    {
        return false;
    }
    if (getX() == n)
    {
        if (m < getY())
        {
            for (int i = getY() - 1; i > m; --i)
            {
                if (!(f_board->positionStatus(n , i)))
                {
                    return false;
                }
            }
        }
        else if (m > getY())
        {
            for (int i = getY() + 1; i < m; ++i)
            {
                if (!(f_board->positionStatus(n , i)))
                {
                    return false;
                }
            }
        }
        return true;
    }
    else if (getY() == m)
    {
        if (n < getX())
        {
            for (int i = getX() - 1; i > n; --i)
            {
                if (!(f_board->positionStatus(i , m)))
                {
                    return false;
                }
            }
        }
        else if (n > getX())
        {
            for (int i = getX() + 1; i < n; ++i)
            {
                if (!(f_board->positionStatus(i , m)))
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}