#include<iostream>


class Matrix
{
public:
    Matrix() = default;
    Matrix(const int& _n , const int& _m);
    Matrix(const Matrix& M);
    Matrix(Matrix&& M);
    Matrix operator=(Matrix&& M);
    Matrix& operator=(const Matrix& M);
    const Matrix operator+(const Matrix& M);
    const Matrix operator-(const Matrix& M);
    const Matrix operator*(const Matrix& M);
    Matrix& operator++();
    Matrix operator++(int);
    ~Matrix();

public:
    void transposeMatrix();
    void printMatrix();
private:
    int** matrix = nullptr;
    int n = 0;
    int m = 0;
};