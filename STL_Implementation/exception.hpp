#ifndef  __exception__
#define __exception__
#include <exception>


namespace mySTL
{
    class out_of_range :public std::exception
    {
        const char* what() const throw() override{
            return "out of range !!!";
        }
    };

};


#endif //__exception__