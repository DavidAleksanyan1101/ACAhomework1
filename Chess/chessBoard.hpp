#ifndef __ChessBoard__
#define __ChessBoard__
#include "Figures/headers/figure.hpp"  


class ChessBoard
{
public:
    ChessBoard();
    bool move(int , int , int , int);
    void setFigure(Figure& , char , int);
    void showBoard();
    bool mateAnalysis(const std::string& color);//1 - white , 0 - black
    bool mateInOneStep(const std::string& color);
    bool mateInTwoStep(const std::string& color);
    bool positionStatus(const int& ,const int&);
    friend class King;
private:
    Figure*** board = nullptr;
};


#endif //__ChessBoard__