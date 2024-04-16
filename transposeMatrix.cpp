#include<iostream>

////////////////////////

int* createMatrix(const int& n , const int& m) {
    int* matrix = new int[n * m];
    for (int i = 0; i < n * m; ++i) {
            matrix[i] = rand() % 10;
    }
    return matrix;
}


void printMatrix(int* matrix , const int& n , const int& m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i * m + j] << ' ';
        }
        std::cout << std::endl;
    }
}

void transposeMatrix(int* matrix , const int& size) {

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            std::swap(matrix[i * size + j] , matrix[j * size + i]);
        }
    }

}



int main() {
    int* matrix1 = createMatrix(4 , 4);
    printMatrix(matrix1 , 4 , 4);

    std::cout<<"transpose matrix"<<std::endl;
    transposeMatrix(matrix1 , 4);
    printMatrix(matrix1 , 4 , 4);
    

    return 0;
}