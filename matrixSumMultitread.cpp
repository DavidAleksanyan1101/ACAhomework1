#include<bits/stdc++.h>
#include<thread>

int columnSum(int** mat , int size , int& sum , int begin , int end)
{
    sum = 0;
    for (int i = begin; i < end; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum += mat[j][i];
        }
    }
    return sum;
}
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    int size = 10;
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = i * 10 + j;
        }
    }


    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         std::cout << matrix[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }


    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;

    std::thread t1(columnSum , std::ref(matrix) , size , std::ref(sum1) , 0 , size / 2);
    std::thread t2(columnSum , std::ref(matrix) , size , std::ref(sum2) , size / 2 , size);

    t1.join();
    t2.join();
    sum = sum1 + sum2;
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << sum << std::endl;

    std::cout << "Elapsed time: " << std::fixed << std::setprecision(10) <<
        elapsed_seconds.count() << " seconds\n";
}