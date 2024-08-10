#include <iostream>
#include<fstream>
#include"chessBoard.hpp"

int main()
{

    ChessBoard b1;
    King BK("black");
    Queen BQ("black");
    King WK("white");
    Rook BR("black");
    Rook WR("white");
    Bishop WB1("white");
    Bishop WB2("white");
    Bishop BB("black");
    Queen WQ("white");
    Knight Wn("white");

    //TEST #1
    // b1.setFigure(BK , 'b' , 5);
    // b1.setFigure(WQ , 'd' , 8);
    // b1.setFigure(WR , 'c' , 3);
    // b1.setFigure(Wn , 'e' , 5);
    // b1.setFigure(WK , 'e' , 4);

    // TEST#2
    // b1.setFigure(BK , 'e' , 4);
    // b1.setFigure(WQ , 'd' , 1);
    // b1.setFigure(WR , 'g' , 6);
    // b1.setFigure(Wn , 'f' , 3);
    // b1.setFigure(WK , 'd' , 2);


    //TEST #3 
    // b1.setFigure(BK , 'e' , 4);
    // b1.setFigure(WQ , 'd' , 1);
    // b1.setFigure(WR , 'g' , 3);
    // b1.setFigure(Wn , 'f' , 3);
    // b1.setFigure(WK , 'd' , 2);

    //TEST #4
    b1.setFigure(BK , 'e' , 4);
    b1.setFigure(WQ , 'B' , 2);
    b1.setFigure(WB1 , 'A' , 1);
    b1.setFigure(WB2 , 'e' , 8);
    b1.setFigure(WK , 'b' , 5);


    b1.showBoard();

    try
    {
        if (b1.mateInTwoStep("black"))
        {
            std::cout << "\033[32m" << "checkmate" << "\033[0m" << std::endl;
        }
        else
        {
            std::cout << "Isn't checkmate" << std::endl;
        }
    }
    catch (const std::string& e)
    {
        std::cerr << e << '\n';
    }



    // b1.showBoard();
    return 0;
}