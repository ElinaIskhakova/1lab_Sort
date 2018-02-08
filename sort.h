#pragma once
#include <iostream>
#include <ctime>


class sort
{
    int RandomSim(int start = 0, int finish = 9);
    void QS(int *arr, int left, int right);
public:
    int *RandomArray(int max);
    int *QSort(int *arr, int max);
    int *LSD_Sort(int *arr, int max);
    sort();
    ~sort();
};
