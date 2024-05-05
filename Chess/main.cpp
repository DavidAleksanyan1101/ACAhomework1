#include <iostream>
#include"king.hpp"
#include"chessBoard.hpp"

int main()
{
    ChessBoard b1;
    King k1("white");
    b1.setFigure(k1 , 1 , 2);
    b1.showBoard();
    std::cout<<std::endl;
    b1.move(4 , 3 , 1 , 3);
    b1.showBoard();

        return 0;
}