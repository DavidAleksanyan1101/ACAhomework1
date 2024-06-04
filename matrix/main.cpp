#include"matrix.hpp"
#include <fstream>
#include<sstream>

// template<typename T>
// void makeMatrixFile(const std::string& s , int n , int m , std::string t )
// {
//     std::ofstream of(s);
//     Matrix<t> mat(n , m);
//     for (int i = 0; i < mat.n; i++)
//     {
//         for (int j = 0; j < mat.m; j++)
//         {
//             of << mat.matrix[i][j] << " ";
//         }
//         of << std::endl;
//     }
// }

// template<typename T>
// void makeMatrixFile(const std::string& s , const Matrix<T>& mat)
// {
//     std::ofstream of(s);
//     for (int i = 0; i < mat.n; i++)
//     {
//         for (int j = 0; j < mat.m; j++)
//         {
//             of << mat.matrix[i][j] << " ";
//         }
//         of << std::endl;
//     }
// }

// template<typename T>
// Matrix<T> readMatrixFile(const std::string& s)
// {
//     std::ifstream rf(s);
//     if (!rf.is_open())
//     {
//         std::cout << "Can't open file" << std::endl;
//         throw std::exception();
//     }
//     int n = 0;
//     int m = 0;
//     std::string line;
//     while (std::getline(rf , line))
//     {
//         std::istringstream sstr(line);
//         ++n;
//         int x;
//         while (sstr >> x)
//         {
//             ++m;
//         }
//     }
//     m = m / n;
//     std::cout << n << "  " << m << std::endl;

//     rf.clear();
//     rf.seekg(0);

//     Matrix mat(n , m);
//     int x = 0;
//     for (int i = 0; i < mat.n; i++)
//     {
//         std::getline(rf , line);
//         std::istringstream sstr(line);
//         for (int j = 0; j < mat.m; j++)
//         {
//             sstr >> x;
//             mat.matrix[i][j] = x;
//         }
//     }
//     return mat;
// }


int main()
{
    Matrix<double> m1(5 , 4);
    Matrix<double> m2(4 , 5);
    makeMatrixFile<float>("Matrix1.txt " , 2  , 2);
    // makeMatrixFile("Matrix2.txt " , m2);
    // Matrix mat1 = readMatrixFile("Matrix1.txt");
    // Matrix mat2 = readMatrixFile("Matrix2.txt");
    // Matrix matrixMult = mat1 * mat2;
    // makeMatrixFile("MatrixMult.txt" , matrixMult);
    return 0;
}