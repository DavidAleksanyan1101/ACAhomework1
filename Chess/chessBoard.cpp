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
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == nullptr)
            {
                std::cout << "0  ";
                continue;
            }
            std::cout << board[i][j]->getName() << "  ";
        }
        std::cout << std::endl;
    }

}

bool ChessBoard::move(int x1 , int y1 , int x2 , int y2)
{
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
