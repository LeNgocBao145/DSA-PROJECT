#ifndef SORT_H
#define SORT_H
#include <iostream>
using namespace std;

// Bubble sort.
void bubbleSort(int *arr, int size, int &comparision);

// Selection sort.
void selectionSort(int *arr, int size, int &comparision);

// Insertion sort.
void insertion_sort(int*& arr, int left, int right, int &comparision);

// Heapify.
void heapify(int* arr, int n, int i, int& comparision);

// Heap sort.
void heapSort(int* arr, int n, int& comparision);

// Merge.
void merge(int* arr, int left, int mid, int right, int& comparision);

// Merge sort.
void mergeSort(int* arr, int left, int right, int& comparision);

// Quick sort.
void quickSort(int* arr, int left, int right, int& comparision);

//Thuật toán sắp xếp cocktail sort hay còn gọi là shaker sort (là bubble sort 2 chiều xuôi và ngược)
void shakerSort(int* arr, int n, int &comparision);

//Thuật toán shell sort sử dụng gap là n/2 cho mỗi bước sort để chia thành nhiều sub - arrays nhỏ qua 
//mỗi lần chia thì gap /= 2 và sort bằng insertion sort
void shellSort(int* arr, int n, int &comparision);

void radixSort(int *arr, int n, int &comparision);
#endif
