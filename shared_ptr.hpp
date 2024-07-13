#ifndef __shared_ptr__
#define __shared_ptr__

template<typename T>
class shared_ptr
{
public:
    shared_ptr() = default;
    shared_ptr(T*);
    shared_ptr(const shared_ptr&);
    ~shared_ptr();
public:
    T& operator*();
    T& operator=(const shared_ptr&);
    T* operator->();
private:
    T* ptr = nullptr;
    int* count = nullptr;
};

template<typename T>
shared_ptr<T>::shared_ptr(T* other) : ptr(other)
{
    count = new int(0);
    ++(*count);
}

template<typename T>
shared_ptr<T>::shared_ptr(const shared_ptr& other) : ptr(other.ptr) , count(other.count)
{
    ++(*count);
}

template<typename T>
shared_ptr<T>::~shared_ptr(){
    --(*count);
    if(*count == 0){
        delete ptr;
        delete count;
    }

}


template<typename T>
T& shared_ptr<T>::operator*()
{
    return *ptr;
}

template<typename T>
T* shared_ptr<T>::operator->()
{
    return ptr;
}

template<typename T>
T& shared_ptr<T>::operator=(const shared_ptr& other)
{
    if(this != &other && other.ptr != ptr){
        --(*count);
        if(*count == 0){
            delete ptr;
            delete count;
        }
        count = other.count;
        ptr = other.ptr;
        ++(*count);
    }

}




#endif //__shared_ptr__