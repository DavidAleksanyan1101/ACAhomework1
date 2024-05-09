#include <iostream>
#include"chessBoard.hpp"

int main()
{
    
    ChessBoard b1;
    King BK("black");
    Rook WR("white");
    Bishop WB("white");
    Queen WQ("white");
    Knight Wk("white");
    b1.setFigure(BK , 7 , 2);
    b1.setFigure(WR , 6 , 7);
    b1.setFigure(WB , 3 , 5);
    b1.setFigure(WQ , 7 , 7);
    b1.setFigure(Wk , 5 , 0);
    b1.showBoard();
    if(b1.mateAnalysis("black")){
        std::cout<<"Mate"<<std::endl;
    }
    else{
        std::cout<<"Isn't mate"<<std::endl;
    }

    return 0;
}