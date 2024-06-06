#ifndef __bubble_sort__
#define __bubble_sort__
#include <utility>
#include <iostream>

void bubble_sort(int *arr, const int &begin, const int &end)
{
    for (int i = begin; i <= end; i++)
    {
        for (int j = 0; j < end - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

#endif //__bubble_sort__