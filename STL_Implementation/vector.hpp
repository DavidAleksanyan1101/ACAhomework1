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
        void push_front(const T&);
        void pop_back();
        void pop_front();
        void insert(const T& , const int&);
        T& operator[](const int&);
        T& at(const int&);
        T& front();
        T& back();
    private:
        T* _arr = nullptr;
        int _capacity = 0;
        int _size = 0;
    };




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
        for (int i = 0; i < _size; i++)
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
    int vector<T>::size()
    {
        return _size;
    }

    template<typename T>
    int vector<T>::capacity()
    {
        return _capacity;
    }

    template<typename T>
    T& vector<T>::operator[](const int& i)
    {
        return _arr[i];
    }

    template<typename T>
    T& vector<T>::at(const int& i)
    {
        if (i >= _size)
        {
            throw std::out_of_range("Invalid index!");
        }
        return _arr[i];
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
        if (_capacity == 0)
        {
            _capacity = 1;
        }
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


    template<typename T>
    void vector<T>::pop_back()
    {
        if (_size != 0)
        {
            --_size;
        }
        return;
    }

    template<typename T>
    void vector<T>::push_front(const T& t)
    {
        if (_size == _capacity)
        {
            _capacity *= 2;
            if (_capacity == 0)
            {
                _capacity = 1;
            }
            T* tmp = new T[_capacity];
            tmp[0] = t;
            for (int i = 0; i < _size; i++)
            {
                tmp[i + 1] = _arr[i];
            }
            delete[] _arr;
            _arr = tmp;
            tmp = nullptr;
            ++_size;
            return;
        }
        for (int i = 0; i < _size; i++)
        {
            _arr[_size - i] = _arr[_size - i - 1];
        }
        _arr[0] = t;
        ++_size;
        return;
    }

    template<typename T>
    void vector<T>::pop_front()
    {
        if (_size == 1)
        {
            --_size;
        }
        else if (_size != 0)
        {
            for (int i = 0; i < _size - 1; i++)
            {
                _arr[i] = _arr[i + 1];
            }
            --_size;
        }
    }

    template<typename T>
    void vector<T>::insert(const T& t , const int& index)
    {
        if (_size == _capacity)
        {
            _capacity *= 2;
            if (_capacity == 0)
            {
                _capacity = 1;
            }
            T* tmp = new T[_capacity];
            for (int i = 0; i < _size; i++)
            {
                tmp[i] = _arr[i];
            }
            delete[] _arr;
            _arr = tmp;
            tmp = nullptr;
        }
        for (int i = 0; i < _size - index; i++)
        {
            _arr[_size - i] = _arr[_size - i - 1];
        }
        _arr[index] = t;
        ++_size;
        return;
    }


    template<typename T>
    T& vector<T>::front()
    {
        if (_size != 0)
        {
            return _arr[0];
        }
    }

    template<typename T>
    T& vector<T>::back()
    {
            return _arr[_size - 1];
    }

#endif //__Vector__