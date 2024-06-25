#include <iostream>
#include "heap.h"
using namespace std;

void heapify(int* arr, int n, int i, int& comparision) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
        comparision++;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        comparision++;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, comparision);
    }
}

void heapSort(int* arr, int n, int& comparision) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparision);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparision);
    }
}