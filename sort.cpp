#include "sort.h"
#include <cstdlib>

int sort::RandomSim(int start, int finish)
{
    return 0 +rand()% 9;
}

int *sort::RandomArray(int max)
{
    int *Array = new int[max];
    for (int i = 0; i < max - 1; i++)
    {
        Array[i] = RandomSim();
    }
    return Array;
}
//int digit( int n, int p) {  // ��������� p-�� �����
//    return (n >> (8 * p) & 255);
//}

//// ���������� ��������� ������� a �� p �����
//void counting_sort ( int *a, int number, const int p) {
//    // ������������ ����� ������ � �����
//     int* b = new  int[number];
//    // � ����� �������� 256 ��������
//    int c[256] = {0};
//    // ������������ ���������� ���������
//    // � ������� ��������������� �������
//    // ����� (�� ���������� ���������)
//    for ( int j = 0; j < number; ++j ) {
//        c[digit(a[j],p)]++;
//    }
//    // ������������ ������ �.
//    // c[i] - ����� ��������, ���������� ����� i-�� �����
//    for ( int j = 1; j < 256; ++j ) {
//        c[j] += c[j - 1];
//    }
//    // C������� ������
//    for ( int j = number - 1; j >= 0; --j ) {
//        b[--c[digit(a[j],p)]] = a[j];
//    }
//    for ( int j = 0; j < number; ++j ) {
//        a[j] = b[j];
//    }
//    delete[] b;
//}

//// ���������� �������  ������� ����������� ���������� LSD �� ������
// int *LSD_Sort(int *a, int max){
//     int max_size = sizeof(int);
//    // ���� �� ���� ������
//    for ( int i = 0; i < max_size; ++i ) {
//        counting_sort(a, max, i);
//    }
//    return a;
//}
int *sort::QSort(int *arr, int max)
{
    QS(arr, 0, max - 2);
    return arr;
}

void sort::QS(int *arr, int left, int right)
{
    int i, j;
    int x, y;
    i = left; j = right;
    x = arr[(left + right) / 2];
    do {
        while ((arr[i] < x) && (i < right)) i++;
        while ((x < arr[j]) && (j > left)) j--;
        if (i <= j) {
            y = arr[i];
            arr[i] = arr[j];
            arr[j] = y;
            i++; j--;
        }
    } while (i <= j);
    if (left < j) QS(arr, left, j); if (i < right) QS(arr, i, right);
}

sort::sort()
{
    srand(time(NULL));
}

sort::~sort()
{
}
