#include <iostream>
#include"chessBoard.hpp"

int main()
{
    ChessBoard b1;
    King BK("black");
    King WK("white");
    Rook WR("white");
    Bishop WB("white");
    Queen WQ("white");
    Knight Wk("white");


    // b1.setFigure(BK , 7 , 2);
    // b1.setFigure(WK , 0 , 4);
    // b1.setFigure(WR , 6 , 7);
    // b1.setFigure(WB , 4 , 5);
    // b1.setFigure(WQ , 0 , 3);
    // b1.setFigure(Wk , 5 , 0);
    // b1.showBoard();

    // b1.setFigure(BK , 5 , 3);
    // b1.setFigure(WK , 0 , 4);
    // b1.setFigure(WR , 1 , 2);
    // b1.setFigure(WB , 4 , 2);
    // b1.setFigure(WQ , 7 , 4);
    // b1.setFigure(Wk , 3 , 5);
    // b1.showBoard();
    
    // b1.setFigure(BK , 5 , 7);
    // b1.setFigure(WK , 0 , 4);
    // b1.setFigure(WR , 6 , 0);
    // b1.setFigure(WB , 2 , 3);
    // b1.setFigure(WQ , 4 , 3);
    // b1.setFigure(Wk , 3 , 7);
    // b1.showBoard();
    
    // b1.setFigure(BK , 4 , 5);
    // b1.setFigure(WK , 0 , 4);
    // b1.setFigure(WR , 0 , 6);
    // b1.setFigure(WB , 6 , 2);
    // b1.setFigure(WQ , 0 , 1);
    // b1.setFigure(Wk , 3 , 3);
    // b1.showBoard();


    if (b1.mateAnalysis("black"))
    {
        std::cout << "Mate" << std::endl;
    }
    else
    {
        std::cout << "Isn't mate" << std::endl;
    }

    return 0;
}