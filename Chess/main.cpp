#include <iostream>
#include"figure.hpp"
#include"chessBoard.hpp"

int main()
{
    ChessBoard b1;
    King k1("white");
    b1.setFigure(k1 , 1 , 2);
    b1.showBoard();
    std::cout<<std::endl;
    b1.move(1 , 2 , 2 , 3);
    std::cout<<k1.getX() << k1.getY()<<std::endl;
    // b1.showBoard();

        return 0;
}