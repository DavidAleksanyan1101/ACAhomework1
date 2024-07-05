#ifndef __ChessBoard__
#define __ChessBoard__
#include "Figures/headers/figure.hpp"  


class ChessBoard
{
public:
    ChessBoard();
    bool move(int , int , int , int);
    void setFigure(Figure& , int , int);
    void showBoard();
    bool mateAnalysis(const std::string& color);//1 - white , 0 - black
    bool mateAfterOneStep(const std::string& color);
    bool positionStatus(const int& ,const int&);
private:
    Figure*** board = nullptr;
};


#endif //__ChessBoard__