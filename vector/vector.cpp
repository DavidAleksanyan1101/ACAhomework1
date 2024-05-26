#include "vector.hpp"
#include<iostream>

template<typename T>
vector<T>::vector(const int& size) : _size(size) , _capacity(size)
{
    std::cout << "param ctor" << std::endl;
    if (size == 0)
    {
        _capacity = 0;
        return;
    }
    _arr = new T[_capacity];
}
template<typename T>
vector<T>::vector(const vector& v) : _size(v._size) , _capacity(v._capacity)
{
    std::cout << "cpy ctor" << std::endl;
    if (_capacity == 0)
    {
        return;
    }
    _arr = new T[_capacity];
    if (_size == 0)
    {
        return;
    }
    for (int i = 0; i < _size; i++)
    {
        _arr[i] = v._arr[i];
    }
}

template<typename T>
vector<T>::vector(vector&& v)
{
    std::cout << "move ctor" << std::endl;
    _size = v._size;
    _capacity = v._capacity;
    _arr = v._arr;

    v._arr = nullptr;
    v._size = 0;
    v._capacity = 0;
}

template<typename T>
vector<T>& vector<T>::operator=(const vector& v)
{
    _size = v._size;
    _capacity = v._capacity;
    if (_capacity == 0)
    {
        _arr = nullptr;
        return this;
    }
    _arr = new T[_capacity];
    if (_size == 0)
    {
        return this;
    }
    for (int i = 0; i < size; i++)
    {
        _arr[i] = v._arr[i];
    }
    return this;
}

template<typename T>
vector<T>& vector<T>::operator=(vector&& v)
{
    delete[] _arr;
    _size = v._size;
    _capacity = v._capacity;
    _arr = v._arr;

    v._arr = nullptr;
    _capacity = 0;
    _size = 0;
}

template<typename T>
vector<T>::~vector()
{
    delete[] _arr;
}

template<typename T>
int vector<T>::size(){
    return _size;
}

template<typename T>
int vector<T>::capacity(){
    return _capacity;
}

template<typename T>
void vector<T>::push_back(const T& elem)
{
    if (_size < _capacity)
    {
        _arr[_size] = elem;
        ++_size;
        return;
    }
    _capacity *= 2;
    T* tmp = new T[_capacity];
    for (int i = 0; i < _size; i++)
    {
        tmp[i] = _arr[i];
    }
    delete[] _arr;
    _arr = tmp;
    tmp = nullptr;
    _arr[_size] = elem;
    ++_size;
    return;
}
