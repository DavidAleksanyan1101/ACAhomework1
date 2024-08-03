#include "../headers/king.hpp"
#include "../../chessBoard.hpp"

King::King(const std::string& color) : Figure(color , "King") {}

bool King::canMove(int n , int m)
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
        // for (int i = 0; i < 3; ++i) 
        // {
        //     for (int j = 0; j < 0; ++j)
        //     {
        //         // f_board->board[i + this->getX() - 1][j + this->getY() - 1]->getName() == "King"
        //         if ( f_board->board[i + this->getX() - 1][j + this->getY() - 1]->getColor() == this->getColor())
        //         {
        //             return false;
        //         }
        //     }
        // }
        return true;
    }
    return false;
}
