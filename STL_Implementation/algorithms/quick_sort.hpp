#ifndef __quick_sort__
#define __quick_sort__
#include <utility>
#include <iostream>

int partition(int *arr, const int &begin, const int &end)
{
    int pivot = arr[end];
    int c = begin - 1;
    for (int i = begin; i < end + 1; i++)
    {
        if (arr[i] < pivot)
        {
            ++c;
            std::swap(arr[i], arr[c]);
        }
    }
    std::swap(arr[c + 1], arr[end]);

    return c + 1;
}

void quick_sort(int *arr, const int &begin , const int &end)
{
    if (end - begin < 1){
        return; 
    }

    int pivot_index = partition(arr , begin , end);

    quick_sort(arr , begin , pivot_index - 1);
    quick_sort(arr , pivot_index + 1 , end);

}

#endif //__quick_sort__