#ifndef __merge_sort__
#define __merge_sort__
#include <iostream>


void merge(int *arr, const int &begin, const int &mid, const int &end)
{
    int firstArrSize = mid - begin + 1;
    int secondArrAize = end - mid;

    int *firstArr = new int[firstArrSize];
    int *secondArr = new int[secondArrAize];

    for (int i = 0; i < firstArrSize; i++)
    {
        firstArr[i] = arr[begin + i];
    }
    for (int i = 0; i < secondArrAize; i++)
    {
        secondArr[i] = arr[mid + 1 + i];
    }

    int firstCount = 0;
    int secondCount = 0;
    int arrCount = begin;

    while (firstCount < firstArrSize && secondCount < secondArrAize)
    {
        if (firstArr[firstCount] <= secondArr[secondCount])
        {
            arr[arrCount] = firstArr[firstCount];
            ++firstCount;
        }
        else
        {
            arr[arrCount] = secondArr[secondCount];
            ++secondCount;
        }
        ++arrCount;
    }

    while (firstCount < firstArrSize)
    {
        arr[arrCount] = firstArr[firstCount];
        ++arrCount;
        ++firstCount;
    }

    while (secondCount < secondArrAize)
    {
        arr[arrCount] = secondArr[secondCount];
        ++arrCount;
        ++secondCount;
    }

    delete[] firstArr;
    delete[] secondArr;
}

void merge_sort(int *arr, const int &begin, const int &end)
{
    if (begin < end)
    {

        int mid = (begin + end) / 2;
        merge_sort(arr, begin, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}

#endif //__merge_sort__
