#include"matrix.hpp"


int main()
{
    Matrix matrix1(6 , 3);
    matrix1.printMatrix();
    std::cout << std::endl;
    // matrix1.transposeMatrix();
    // matrix1.printMatrix();
    Matrix matrix2(6 , 3);
    matrix2.printMatrix();
    std::cout << std::endl;
    
    Matrix matrix3;
    matrix3 = matrix1 + matrix2;
    matrix3.printMatrix();


    return 0;
}