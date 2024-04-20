#include <iostream>



class Matrix
{
public:
    Matrix() = default;
    Matrix(const int& _n , const int& _m) : n(_n) , m(_m)
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

    Matrix(const Matrix& M)
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

    Matrix& operator=(const Matrix& M)
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


    }

    ~Matrix()
    {
        for (int i = 0; i < n; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void transposeMatrix()
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

    void printMatrix()
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
private:
    int** matrix = nullptr;
    int n = 0;
    int m = 0;
};

int main()
{
    Matrix matrix1(6 , 3);
    matrix1.printMatrix();
    std::cout << std::endl;
    // matrix1.transposeMatrix();
    // matrix1.printMatrix();
    Matrix matrix2;
    matrix2 = matrix1;
    matrix2.printMatrix();

    return 0;
}