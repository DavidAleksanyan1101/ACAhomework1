#ifndef __Figure__
#define __Figure__
#include<iostream>

class ChessBoard;

class Figure
{
public:
    Figure(const std::string &, const std::string &);
    virtual ~Figure();
public:
    virtual bool canMove(int, int) = 0;
    std::string getName();
    std::string getColor();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void setBoard(ChessBoard *b);
protected:
    ChessBoard *f_board;
private:
    std::string _color;
    std::string _name;
    int x = 0;
    int y = 0;
};

#include "king.hpp"
#include "queen.hpp"
#include "bishop.hpp"
#include "rook.hpp"
#include "knight.hpp"

#endif //__Figure__