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
//int digit( int n, int p) {  // Получение p-го байта
//    return (n >> (8 * p) & 255);
//}

//// Сортировка подсчётом массива a по p байту
//void counting_sort ( int *a, int number, const int p) {
//    // Максимальное число байтов в числе
//     int* b = new  int[number];
//    // У байта максимум 256 значений
//    int c[256] = {0};
//    // Подсчитываем количество элементов
//    // в массиве соответствующий каждому
//    // байту (из сортировок подсчетом)
//    for ( int j = 0; j < number; ++j ) {
//        c[digit(a[j],p)]++;
//    }
//    // Модифицируем массив с.
//    // c[i] - номер элемента, следующего после i-го блока
//    for ( int j = 1; j < 256; ++j ) {
//        c[j] += c[j - 1];
//    }
//    // Cдвигаем массив
//    for ( int j = number - 1; j >= 0; --j ) {
//        b[--c[digit(a[j],p)]] = a[j];
//    }
//    for ( int j = 0; j < number; ++j ) {
//        a[j] = b[j];
//    }
//    delete[] b;
//}

//// Сортировка массива  методом поразрядной сортировки LSD по байтам
// int *LSD_Sort(int *a, int max){
//     int max_size = sizeof(int);
//    // Цикл по всем байтам
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
