#include "../headers/queen.hpp"
#include "../../chessBoard.hpp"

Queen::Queen(const std::string& color) : Figure(color , "Queen") {}

bool Queen::canMove(int n , int m)
{
    if (n >= 8 || m >= 8 || n < 0 || m < 0)
    {
        throw std::out_of_range("invalid position");
    }
    if (n == getX() && m == getY())
    {
        return false;
    }
    if (getX() == n ^ getY() == m)
    {
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
                return true;
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
                return true;
            }
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
                return true;
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
                return true;
            }
        }
    }
    else if (getX() + getY() == n + m || getX() - n == getY() - m)
    {
        if (getX() - n == getY() - m)
        {
            if (getX() < n)
            {
                for (int i = 1; i < n - getX(); ++i)
                {
                    if (!(f_board->positionStatus(getX() + i , getY() + i)))
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
                    if (!(f_board->positionStatus(n + i , m + i)))
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
                    if (!(f_board->positionStatus(getX() + i , getY() - i)))
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
                    if (!(f_board->positionStatus(n + i , m - i)))
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}
