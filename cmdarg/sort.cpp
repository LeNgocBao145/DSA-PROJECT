#include <iostream>

#include "sort.h"
using namespace std;

// Bubble sort.
void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Selection sort.
void selectionSort(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

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

void merge(int* arr, int left, int mid, int right, int& comparision) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparision++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int* arr, int left, int right, int& comparision) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, comparision);
        mergeSort(arr, mid + 1, right, comparision);

        merge(arr, left, mid, right, comparision);
    }
}
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


void shakerSort(int arr[], int n)
{
    int head = 0;
    int tail = n - 1;

    while(head < tail)
    {
        for(int i = head; i < tail; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }

        for(int i = tail - 1; i > head; i--)
        {
            if(arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
            }
        }

        head++;
        tail--;
    }
}

void shellSort(int arr[], int n)
{
    int gap = n / 2;

    while(gap != 0)
    {
        for(int i = 0; i < n; i++)
        {
            int index = i;
            int temp = arr[i];
            while(temp < arr[index - gap] && index - gap >= 0)
            {
                arr[index] = arr[index - gap];
                index -= gap;
            }

            arr[index] = temp;
        }


        gap /= 2;
    } 
}

