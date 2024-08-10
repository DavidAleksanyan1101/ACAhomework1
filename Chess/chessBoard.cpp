#include "chessBoard.hpp"
#include "sstream"

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

void ChessBoard::setFigure(Figure& f , char ch , int n)
{
    n = 8 - n;
    int m = int(toupper(ch)) - 65;
    // std::cout<<int(ch)<<m<<std::endl;
    static short w_king = 0;
    static short b_king = 0;
    if (n >= 8 || m >= 8 || n < 0 || m < 0)
    {
        throw std::out_of_range("invalid position!");
    }
    if (board[n][m] != nullptr)
    {
        throw std::invalid_argument("That place is busy , can't set! ");
    }
    if (f.getName() == "King")
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i + n - 1 < 0 || i + n - 1 > 7)
                {
                    continue;
                }
                if (j + m - 1 < 0 || j + m - 1 > 7)
                {
                    continue;
                }

                if (board[i + n - 1][j + m - 1] != nullptr && board[i + n - 1][j + m - 1]->getName() == "King")
                {
                    throw std::logic_error("there is a king near that place!!!");
                }
            }
        }
        if (f.getColor() == "white")
        {
            if (w_king >= 1)
            {
                throw std::out_of_range("Too many white kings");
            }
            ++w_king;
        }
        if (f.getColor() == "black")
        {
            if (b_king >= 1)
            {
                throw std::out_of_range("Too many black kings");
            }
            ++b_king;
        }
    }
    board[n][m] = &f;
    f.setX(n);
    f.setY(m);
    f.setBoard(this);
}

void ChessBoard::showBoard()
{
    std::cout << "  -------------------------------------------------" << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        std::cout << 8 - i << " ";
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
                    std::cout << " BN  |";
                }
                else
                {
                    std::cout << " WN  |";
                }
            }
        }
        std::cout << std::endl;
        std::cout << "  -------------------------------------------------" << std::endl;
    }
    std::cout << "     A     B     C     D     E     F     G     H" << std::endl << std::endl;

}

bool ChessBoard::pureMove(int x1 , int y1 , int x2 , int y2)
{
    if (x1 >= 8 || y1 >= 8 || x2 >= 8 || y2 >= 8)
    {
        throw std::out_of_range("invalid position");
    }
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
    {
        throw std::out_of_range("invalid position");
    }
    if (board[x1][y1] == nullptr)
    {
        std::cout << "place is empty" << std::endl;
        return false;
    }
    // if (board[x2][y2] == nullptr)
    // {
    // if (board[x1][y1]->getName() == "King")
    // {
        // std::cout<<"king m"<<std::endl;
        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         if (i + x2 - 1 == x1 && j + y2 - 1 == y1)
        //         {
        //             continue;
        //         }
        //         if (i + x2 - 1 < 0 || i + x2 - 1 > 7)
        //         {
        //             continue;
        //         }
        //         if (j + y2 - 1 < 0 || j + y2 - 1 > 7)
        //         {
        //             continue;
        //         }

                // if (isCheck(x2 , y2 , board[x1][y1]->getColor()))
                // {
                //     std::cout<<board[x1][y1]->getColor() << "king move" << std::endl;
                //     // std::cout << "king here!!!" << std::endl;
                //     return false;
                // }
            // }
    //     }
    // }
    if (board[x1][y1]->canMove(x2 , y2) == true)
    {
        board[x2][y2] = board[x1][y1];
        board[x2][y2]->setX(x2);
        board[x2][y2]->setY(y2);
        board[x1][y1] = nullptr;
        return true;
    }
    // std::cout << "Can't move to that place" << std::endl;
    return false;
    // }
    // std::cout << "That place is busy" << std::endl;
    return false;
}

bool ChessBoard::move(int x1 , int y1 , int x2 , int y2)
{
    if (x1 >= 8 || y1 >= 8 || x2 >= 8 || y2 >= 8)
    {
        throw std::out_of_range("invalid position");
    }
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
    {
        throw std::out_of_range("invalid position");
    }
    if (board[x1][y1] == nullptr)
    {
        std::cout << "place is empty" << std::endl;
        return false;
    }
    // if (board[x2][y2] == nullptr)
    // {
    if (board[x1][y1]->getName() == "King")
    {
        // std::cout<<"king m"<<std::endl;
        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         if (i + x2 - 1 == x1 && j + y2 - 1 == y1)
        //         {
        //             continue;
        //         }
        //         if (i + x2 - 1 < 0 || i + x2 - 1 > 7)
        //         {
        //             continue;
        //         }
        //         if (j + y2 - 1 < 0 || j + y2 - 1 > 7)
        //         {
        //             continue;
        //         }

        if (isCheck(x2 , y2 , board[x1][y1]->getColor()))
        {
            // std::cout << board[x1][y1]->getColor() << "  king move" << std::endl;
            // std::cout << "king here!!!" << std::endl;
            return false;
            // }
        // }
        }
    }
    if (board[x1][y1]->canMove(x2 , y2) == true)
    {
        // std::cout << "mv " << board[x1][y1]->getName() << std::endl;
        board[x2][y2] = board[x1][y1];
        board[x2][y2]->setX(x2);
        board[x2][y2]->setY(y2);
        board[x1][y1] = nullptr;
        return true;
    }
    // std::cout << "Can't move to that place" << std::endl;
    return false;
    // }
    // std::cout << "That place is busy" << std::endl;
    return false;
}


bool ChessBoard::isCheck(int x , int y , std::string color)
{
    bool check = false;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] != nullptr && board[i][j]->getColor() != color)
            {
                if (board[i][j]->canMove(x , y))
                {
                    check = true;
                    break;
                }
            }
        }
        if (check == true)
        {
            break;
        }
    }
    return check;
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
    bool kingFound = false;
    for (int i = 7; i >= 0; --i)
    {
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
    if (kingFound == false)
    {
        // showBoard();
        throw std::string("King isn't found");
    }
    // std::cout << kingX << kingY << std::endl;


    bool check = false;
    for (int i = 0; i < 8 && !check; ++i)
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
    }
    if (check != true)
    {
        // std::cout << "isn't  check" << std::endl;
        return false;
    }
    // std::cout << "check" << std::endl;


    int checkX = 3;
    int checkY = 3;
    for (int i = 0; i < checkX; ++i)
    {
        for (int j = 0; j < checkY; ++j)
        {
            bool canMove = true;
            if (i == 1 && j == 1)
            {
                continue;
            }
            if (i + kingX - 1 < 0 || i + kingX - 1 > 7)
            {
                continue;
            }
            if (j + kingY - 1 < 0 || j + kingY - 1 > 7)
            {
                continue;
            }
            // std::cout<<i + kingX - 1<<" "<<j + kingY - 1<<std::endl;
            Figure* temp = board[i + kingX - 1][j + kingY - 1];
            if (move(kingX , kingY , i + kingX - 1 , j + kingY - 1))
            {
                for (int n = 0; n < 8; ++n)
                {
                    for (int k = 0; k < 8; ++k)
                    {
                        if (board[n][k] != nullptr)
                        {
                            if (board[n][k]->getColor() == attackColor)
                            {
                                // std::cout << "canmove check " << board[n][k]->getName() << std::endl;
                                // std::cout<<board[n][k]->canMove(i + kingX - 1 , j + kingY - 1)<<std::endl;

                                if (board[n][k]->canMove(i + kingX - 1 , j + kingY - 1))
                                {
                                    // std::cout << "can move true" << std::endl;
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
                    // std::cout << "false for " << i + kingX - 1 << " " << j + kingY - 1 << " " << kingX << " " << kingY << std::endl;
                    if (pureMove(i + kingX - 1 , j + kingY - 1 , kingX , kingY))
                    {
                        // std::cout << "temp rev" << std::endl;
                        board[i + kingX - 1][j + kingY - 1] = temp;
                    }
                    return false;
                }
                pureMove(i + kingX - 1 , j + kingY - 1 , kingX , kingY);
                board[i + kingX - 1][j + kingY - 1] = temp;
            }
        }
    }
    return true;
}

bool ChessBoard::positionStatus(const int& n , const int& m)
{
    if (board[n][m] == nullptr)
    {
        return true;
    }
    return false;
}

bool ChessBoard::mateInOneStep(const std::string& color)
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
    if (mateAnalysis(mateColor))
    {
        std::cout << "it is already mate" << std::endl;
        return true;
    }
    int kingX = 0;
    int kingY = 0;
    bool kingFound = false;
    for (int i = 7; i >= 0; --i)
    {
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
    if (kingFound == false)
    {
        throw std::string("King isn't found");
    }
    // std::cout << kingX << kingY << std::endl;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != nullptr)
            {
                if (board[i][j]->getColor() == attackColor)
                {
                    // std::cout << board[i][j]->getName() << std::endl;
                    // std::cout << board[i][j]->getColor() << std::endl;
                    for (int k = 0; k < 8; k++)
                    {
                        for (int n = 0; n < 8; n++)
                        {
                            if (k == kingX && n == kingY)
                            {
                                continue;
                            }
                            if (board[k][n] != nullptr && board[k][n]->getColor() == attackColor)
                            {
                                continue;
                            }
                            if (board[i][j]->canMove(k , n))
                            {
                                // std::cout << k << " " << n << std::endl;
                                // std::string tempName;
                                // if (board[k][n] != nullptr)
                                // {
                                //     tempName = board[k][n]->getName();
                                // }
                                // std::cout << i << " " << j << std::endl;
                                if (this->move(i , j , k , n))
                                {
                                    // std::cout<<"move"<<std::endl;
                                    if (mateAnalysis(mateColor))
                                    {
                                        std::cout << board[k][n]->getColor() << " " << board[k][n]->getName() << " to " << char(n + 65) << "" << 8 - k << std::endl;
                                        this->move(k , n , i , j);

                                        return true;
                                    }
                                    this->move(k , n , i , j);
                                }
                                // std::cout<<"reverse move"<<std::endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}


bool ChessBoard::mateInTwoStep(const std::string& color)
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
    if (mateAnalysis(mateColor))
    {
        std::cout << "it is already checkmate" << std::endl;
        return true;
    }
    else if (mateInOneStep(mateColor))
    {
        std::cout << "Checkmate in one step" << std::endl;
        return true;
    }
    int kingX = 0;
    int kingY = 0;
    bool kingFound = false;
    for (int i = 7; i >= 0; --i)
    {
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
    if (kingFound == false)
    {
        throw std::string("King isn't found");
    }
    // std::cout << kingX << kingY << std::endl;
    std::stringstream sstr("");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != nullptr && board[i][j]->getColor() == attackColor)
            {
                // std::cout << board[i][j]->getName();
                // std::cout << board[i][j]->getColor() << std::endl;
                for (int k = 0; k < 8; k++)
                {
                    for (int n = 0; n < 8; n++)
                    {
                        if (k == kingX && n == kingY)
                        {
                            continue;
                        }
                        if (board[k][n] != nullptr && board[k][n]->getColor() == attackColor)
                        {
                            continue;
                        }
                        if (board[i][j]->canMove(k , n))
                        {
                            // std::cout << "out for" << i << j << k << n << std::endl;

                            if (move(i , j , k , n))
                            {
                                // std::cout << "king step" << std::endl;
                                for (int u = 0; u < 3; u++)
                                {
                                    for (int l = 0; l < 3; l++)
                                    {
                                        if (u == 1 & l == 1)
                                        {
                                            continue;
                                        }
                                        if (u + kingX - 1 < 0 || u + kingX - 1 > 7)
                                        {
                                            continue;
                                        }
                                        if (l + kingY - 1 < 0 || l + kingY - 1 > 7)
                                        {
                                            continue;
                                        }
                                        //                                     // std::cout << "move if" << std::endl;
                                        // std::cout << kingX << " " << kingY << " " << u + kingX - 1 << " " << l + kingY - 1 << std::endl;
                                                                            // std::cout << move(kingX , kingY , u + kingX - 1 , l + kingY - 1) << std::endl;
                                                                            // std::cout << pureMove(u + kingX - 1 , l + kingY - 1 , kingX , kingY) << std::endl;
                                        Figure* temp = board[u + kingX - 1][l + kingY - 1];
                                        if (move(kingX , kingY , u + kingX - 1 , l + kingY - 1))
                                        {
                                            sstr.clear();
                                            sstr.str("");
                                            sstr << board[k][n]->getColor() << " " << board[k][n]->getName() << " to " << char(n + 65) << "" << 8 - k << std::endl;
                                            sstr << board[u + kingX - 1][l + kingY - 1]->getColor() << " " << board[u + kingX - 1][l + kingY - 1]->getName() << " to " << char(l + kingY - 1 + 65) << 8 - (u + kingX - 1) << std::endl;
                                            std::streambuf* originalBuffer = std::cout.rdbuf();
                                            std::cout.rdbuf(sstr.rdbuf());
                                            if (mateInOneStep(mateColor))
                                            {
                                                std::cout.rdbuf(originalBuffer);
                                                std::cout << sstr.str() << std::endl;
                                                // std::cout << "one tep check" << std::endl;
                                                move(k , n , i , j);
                                                pureMove(u + kingX - 1 , l + kingY - 1 , kingX , kingY);
                                                return true;
                                            }
                                            if (pureMove(u + kingX - 1 , l + kingY - 1 , kingX , kingY))
                                            {
                                                board[u + kingX - 1][l + kingY - 1] = temp;
                                                std::cout << "king move" << std::endl;
                                            }
                                        }
                                    }
                                }
                                move(k , n , i , j);
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}