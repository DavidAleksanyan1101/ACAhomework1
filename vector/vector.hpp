#ifndef __Vector__
#define __Vector__

template<typename T>
class vector
{
public:
    vector() = default; //defult ctor
    vector(const int&);//param ctor
    vector(const vector&);//cpy ctor
    vector(vector&&);//move ctor
    vector& operator=(const vector&);//operator=
    vector& operator=(vector&&);//move operator=
    ~vector();
public:
    int size();
    int capacity();
    void push_back(const T&);

private:
    T* _arr = nullptr;
    int _capacity = 0;
    int _size = 0;
};

#endif //__Vector__