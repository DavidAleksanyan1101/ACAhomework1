#include"matrix.hpp"

Matrix::Matrix(const int& _n , const int& _m) : n(_n) , m(_m)
{
    matrix = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
}

Matrix::Matrix(const Matrix& M)
{
    this->n = M.n;
    this->m = M.m;
    matrix = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = M.matrix[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& M)
{
    for (int i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    this->n = M.n;
    this->m = M.m;
    matrix = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = M.matrix[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix& M)
{
    if (n != M.n || m != M.m)
    {
        std::cout << "Size of matrixes must be equal , returned empty matrix" << std::endl;
        return Matrix();
    }
    Matrix result(n , m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            result.matrix[i][j] = matrix[i][j] + M.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& M)
{
    if (n != M.n || m != M.m)
    {
        std::cout << "Size of matrixes must be equal , returned empty matrix" << std::endl;
        return Matrix();
    }
    Matrix result(n , m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            result.matrix[i][j] = matrix[i][j] - M.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& M)
{
    if (m != M.n)
    {
        std::cout << "Can't multiple that matrixes" << std::endl;
        return Matrix();
    }
    Matrix result(n , M.m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M.m; ++j)
        {
            result.matrix[i][j] = 0;
            for (int n = 0; n < m; ++n)
            {
                result.matrix[i][j] += matrix[i][n] * M.matrix[n][j];
            }
        }
    }
    return result;
}



Matrix::~Matrix()
{
    for (int i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::transposeMatrix()
{
    Matrix newMatrix(m , n);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            newMatrix.matrix[i][j] = matrix[j][i];
        }
    }
    std::swap(matrix , newMatrix.matrix);
    std::swap(n , m);
}

void Matrix::printMatrix()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}