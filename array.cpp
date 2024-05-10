#include <iostream>

class Array{
public:
    Array() = default;
    Array(const int& size) : _size(size){
        _arr = new int[size];
    }
    Array(const Array& a)  : _size(a._size){
        _arr = new int[_size];
    }
    Array& operator=(const Array& a){
        this->_size = a._size;
        delete [] _arr;
        _arr = new int[_size];
    }
    ~Array(){
        delete [] _arr;
    }

    int getSize(){
        return _size;
    }
    
    int& operator[](const int& a){
        return _arr[a];
    }

    friend std::ostream& operator << (std::ostream& os, const Array& arr);
private:
    int* _arr = nullptr;
    int _size = 0;
};


std::ostream& operator << (std::ostream& os, const Array& arr)
{
    os << arr._arr[0];
    return os;
}

int main() {
    int arr[10];
    arr[0]=15;
    std::cout<<*arr<<std::endl;
    Array arr1(5);
    arr1[0] = 12;
    std::cout<< arr1;
    

    return 0;
}