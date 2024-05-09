#include "chessBoard.hpp"

ChessBoard::ChessBoard()
{
    board = new Figure * *[8];
    for (int i = 0; i < 8; ++i)
    {
        board[i] = new Figure * [8];
    }
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            board[i][j] = nullptr;
        }
    }
}

bool ChessBoard::setFigure(Figure& f , int n , int m)
{
    if (board[n][m] != nullptr)
    {
        std::cout << "That place is busy , can't set" << std::endl;
        return false;
    }
    board[n][m] = &f;
    f.setX(n);
    f.setY(m);
}

void ChessBoard::showBoard()
{
    std::cout << "-------------------------------------------------" << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "|";
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == nullptr)
            {
                std::cout << "     |";
                continue;
            }
            if (board[i][j]->getName() == "Queen")
            {
                if (board[i][j]->getColor() == "black")
                {
                    std::cout << " BQ  |";
                }
                else
                {
                    std::cout << " WQ  |";
                }
            }
            else if (board[i][j]->getName() == "King")
            {
                if (board[i][j]->getColor() == "black")
                {
                    std::cout << " BK  |";
                }
                else
                {
                    std::cout << " WK  |";
                }
            }
            else if (board[i][j]->getName() == "Bishop")
            {
                if (board[i][j]->getColor() == "black")
                {
                    std::cout << " BB  |";
                }
                else
                {
                    std::cout << " WB  |";
                }
            }
            else if (board[i][j]->getName() == "Rook")
            {
                if (board[i][j]->getColor() == "black")
                {
                    std::cout << " BR  |";
                }
                else
                {
                    std::cout << " WR  |";
                }
            }
            else if (board[i][j]->getName() == "Knight")
            {
                if (board[i][j]->getColor() == "black")
                {
                    std::cout << " Bk  |";
                }
                else
                {
                    std::cout << " Wk  |";
                }
            }
        }
        std::cout << std::endl;
        std::cout << "-------------------------------------------------" << std::endl;
    }

}

bool ChessBoard::move(int x1 , int y1 , int x2 , int y2)
{
    if (x1 >= 8 || y1 >= 8 || x2 >= 8 || y2 >= 89)
    {
        std::cout << "out of board" << std::endl;
        return false;
    }
    if (board[x1][y1] == nullptr)
    {
        std::cout << "place is empty" << std::endl;
        return false;
    }
    if (board[x2][y2] == nullptr)
    {
        if (board[x1][y1]->canMove(x2 , y2) == true)
        {
            board[x2][y2] = board[x1][y1];
            board[x2][y2]->setX(x2);
            board[x2][y2]->setY(y2);
            board[x1][y1] = nullptr;
            return true;
        }
        std::cout << "Can't move to that place" << std::endl;
        return false;
    }
    std::cout << "That place is busy" << std::endl;
}


bool ChessBoard::mateAnalysis(const std::string& color)
{
    std::string attackColor;
    std::string mateColor;
    if (color == "black")
    {
        attackColor = "white";
        mateColor = "black";
    }
    else
    {
        attackColor = "black";
        mateColor = "white";
    }

    int kingX = 0;
    int kingY = 0;
    for (int i = 7; i >= 0; --i)
    {
        bool kingFound = false;
        for (int j = 7; j >= 0; --j)
        {
            if (board[i][j] != nullptr)
            {
                if (board[i][j]->getColor() == mateColor && board[i][j]->getName() == "King")
                {
                    kingX = board[i][j]->getX();
                    kingY = board[i][j]->getY();
                    kingFound = true;
                    break;
                }
            }
        }
        if (kingFound == true)
        {
            break;
        }
    }
    // std::cout << kingX << kingY << std::endl;
    bool check = false;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] != nullptr)
            {
                if (board[i][j]->getColor() == attackColor)
                {
                    if (board[i][j]->canMove(kingX , kingY))
                    {
                        check = true;
                        break;
                    }
                }
            }
        }
        if (check == true)
        {
            break;
        }
    }
    if (check != true)
    {
        return false;
    }
    // std::cout << check << std::endl;

    int checkX = 0;
    int checkY = 0;
    if (kingX < 7 && kingY < 7)
    {
        checkX = 3;
        checkY = 3;
    }
    else if (kingX == 7 && kingY < 7)
    {
        checkX = 2;
        checkY = 3;
    }
    else if (kingX < 7 && kingY == 7)
    {
        checkX = 3;
        checkY = 2;
    }
    else if (kingX == 7 && kingY == 7)
    {
        checkX = 2;
        checkY = 2;
    }
    // std::cout << checkX << checkY << std::endl;
    for (int i = 0; i < checkX; ++i)
    {
        for (int j = 0; j < checkY; ++j)
        {
            bool canMove = true;
            if (i == 1 && j == 1)
            {
                continue;
            }

            for (int n = 0; n < 8; ++n)
            {
                for (int k = 0; k < 8; ++k)
                {
                    if (board[n][k] != nullptr)
                    {
                        if (board[n][k]->getColor() == attackColor)
                        {
                            if (board[n][k]->canMove(i + kingX - 1 , j + kingY - 1))
                            {
                                canMove = false;
                                break;
                            }

                        }

                    }
                }
                if (canMove == false)
                {
                    break;
                }
            }
            if (canMove == true)
            {
                return false;
            }
        }
    }
    return true;
}



