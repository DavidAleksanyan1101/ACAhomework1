#include <iostream>
#include<fstream>
#include"chessBoard.hpp"

int main()
{
    close(1);
    open(text.txt);
    ChessBoard b1;
    King BK("black");
    Queen BQ("black");
    King WK("white");
    Rook BR("black");
    Rook WR("white");
    Bishop WB("white");
    Bishop BB("black");
    Queen WQ("white");
    Knight Wn("white");

    // b1.setFigure(WB , 1 , 4);
    // b1.setFigure(BQ , 0 , 0);
    // b1.setFigure(BR , 0 , 5);
    // b1.setFigure(WQ , 6 , 4);
    // b1.setFigure(WR , 3 , 7);
    b1.setFigure(BK , 'e' , 2);
    // b1.setFigure(BK , 0 , 6);
    // b1.setFigure(Wk , 6 , 2);
    // b1.setFigure(Wk , 6 , 4);
    // b1.setFigure(WK , 1 , 4);
    // b1.setFigure(Wn , 1 , 4);

    // std::cout<<int('A')<<std::endl;
    b1.showBoard();
   

    // if (b1.mateInOneStep("black"))
    // {
    //     std::cout <<"\033[32m"<< "checkmate"<<"\033[0m"<< std::endl;
    // }
    // else
    // {
    //     std::cout << "Isn't checkmate" << std::endl;
    // }

    // b1.showBoard();
    return 0;
}