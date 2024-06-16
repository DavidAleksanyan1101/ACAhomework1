#include "../headers/figure.hpp"
#include "../../chessBoard.hpp"


Figure::Figure(const std::string& color , const std::string& name) : _color(color) , _name(name) {}

Figure::~Figure() {}

std::string Figure::getName(){
    return _name;
}
std::string Figure::getColor(){
    return _color;
}
int Figure::getX(){
    return x;
}
int Figure::getY(){
    return y;
}
void Figure::setX(int a){
    x = a;
}
void Figure::setY(int a){
    y = a;
}
void Figure::setBoard(ChessBoard* b){
    board = b;
}