#ifndef __ChessBoard__
#define __ChessBoard__
#include "figure.hpp"


class ChessBoard
{
public:
    ChessBoard();
    bool move(int , int , int , int);
    bool setFigure(Figure& , int , int);
    void showBoard();
    bool mateAnalysis(const std::string& color);//1 - white , 0 - black
private:
    Figure*** board = nullptr;
};


#endif //__ChessBoard__