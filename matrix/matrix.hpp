#include<iostream>


class Matrix
{
public:
    Matrix() = default;
    Matrix(const int& _n , const int& _m);
    Matrix(const Matrix& M);
    Matrix& operator=(const Matrix& M);
    Matrix operator+(const Matrix& M);
    Matrix operator-(const Matrix& M);
    Matrix operator*(const Matrix& M);
    ~Matrix();

public:
    void transposeMatrix();
    void printMatrix();
private:
    int** matrix = nullptr;
    int n = 0;
    int m = 0;
};