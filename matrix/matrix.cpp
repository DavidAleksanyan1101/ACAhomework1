#include"matrix.hpp"

template<typename T>
Matrix<T>::Matrix(const int& _n , const int& _m) : n(_n) , m(_m)
{
    std::srand(time(0));
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

template<typename T>
Matrix<T>::Matrix(const Matrix& M)
{
    std::srand(time(0));
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

template<typename T>
Matrix<T>::Matrix(Matrix&& M)
{
    std::cout << "move ctor" << std::endl;
    matrix = M.matrix;
    n = M.n;
    m = M.m;

    M.matrix = nullptr;
    M.n = 0;
    M.m = 0;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& M)
{
    std::cout << "move =" << std::endl;
    if (this != &M)
    {
        for (int i = 0; i < n; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        matrix = M.matrix;
        n = M.n;
        m = M.m;

        M.matrix = nullptr;
        M.n = 0;
        M.m = 0;
    }
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& M)
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

template<typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix& M)
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

template<typename T>
const Matrix<T> Matrix<T>::operator-(const Matrix& M)
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

template<typename T>
const Matrix<T> Matrix<T>::operator*(const Matrix& M)
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


template<typename T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template<typename T>
void Matrix<T>::transposeMatrix()
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

template<typename T>
void Matrix<T>::printMatrix()
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

template<typename T>
Matrix<T>& Matrix<T>::operator++()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] += 3;
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator++(int)
{
    Matrix temp = *this;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] += 3;
        }
    }
    return temp;
}
