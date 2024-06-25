#include <iostream>
#include "quick.h"
using namespace std;

void quickSort(int* arr, int left, int right, int& comparision) {
    if (left >= right) return;

    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
            comparision++;
        }
        while (arr[j] > pivot) {
            j--;
            comparision++;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quickSort(arr, left, j, comparision);
    quickSort(arr, i, right, comparision);
}
