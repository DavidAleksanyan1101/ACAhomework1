#include "../headers/pawn.hpp"
#include "../../chessBoard.hpp"

Pawn::Pawn(const std::string& color) : Figure(color , "Pawn") {}

bool Pawn::canMove(int n , int m) {
    if (n >= 8 || m >= 8 || n < 0 || m < 0) {
        throw std::out_of_range("invalid position");
    }
    if (n == getX() && m == getY()) {
        return false;
    }
    if (getColor() == "white") {
        if (n - getX() == 1 && abs(m - getY()) == 1) {
            return true;
        }
    }
    if (getColor() == "black") {
        if (getX() - n == 1 && abs(m - getY()) == 1) {
            return true;
        }
    }
}
