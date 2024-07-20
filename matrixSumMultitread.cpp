#include<iostream>
#include<thread>

void f(){

    std::cout<<f<<std::endl;
}

int main(){
    int matrix[1000][1000];
    std::thread t1(f);
    auto start = std::chrono::high_resolution_clock::now();

    int sum = 0;
    for(int i = 0 ; i < 1000 ; i++){
        for(int j = 0 ; j< 1000 ; j++){
            sum += matrix[i][j];
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout<<sum<<std::endl;

    std::cout << "Elapsed time: " << elapsed_seconds.count() << " seconds\n";
}