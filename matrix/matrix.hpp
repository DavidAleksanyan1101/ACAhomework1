#include<iostream>
#include<ctime>


class Matrix
{
public:
    Matrix() = default;
    Matrix(const int& _n , const int& _m);
    Matrix(const Matrix& M);
    // Matrix(Matrix&& M);
    // Matrix operator=(Matrix&& M);
    Matrix& operator=(const Matrix& M);
    const Matrix operator+(const Matrix& M);
    const Matrix operator-(const Matrix& M);
    const Matrix operator*(const Matrix& M);
    Matrix& operator++();
    Matrix operator++(int);
    ~Matrix();
    friend void makeMatrixFile(const std::string& s , int , int );
    friend void makeMatrixFile(const std::string& s ,const Matrix&);
    friend Matrix& readMatrixFile(const std::string&);
public:
    void transposeMatrix();
    void printMatrix();
private:
    int** matrix = nullptr;
    int n = 0;
    int m = 0;
};