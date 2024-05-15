#include "queen.hpp"
#include "chessBoard.hpp"

Queen::Queen(const std::string& color) : Figure(color , "Queen") {}

bool Queen::canMove(int n , int m)
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
        if (getX() == n)
        {
            if (m < getY())
            {
                for (int i = getY() - 1; i > m; --i)
                {
                    if (!(board->positionStatus(n , i)))
                    {
                        return false;
                    }
                }
            }
            else if (m > getY())
            {
                for (int i = getY() + 1; i < m; ++i)
                {
                    if (!(board->positionStatus(n , i)))
                    {
                        return false;
                    }
                }
            }
        }
        else if (getY() == m)
        {
            if (n < getX())
            {
                for (int i = getX() - 1; i > n; --i)
                {
                    if (!(board->positionStatus(i , m)))
                    {
                        return false;
                    }
                }
            }
            else if (n > getX())
            {
                for (int i = getX() + 1; i < n; ++i)
                {
                    if (!(board->positionStatus(i , m)))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    else  if (getX() + getY() == n + m || getX() - n == getY() - m)
    {
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
            }
            return true;
        }
    }
}
