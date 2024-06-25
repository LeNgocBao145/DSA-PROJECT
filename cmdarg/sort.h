#ifndef SORT_H
#define SORT_H
void heapify(int* arr, int n, int i, int& comparision);
void heapSort(int* arr, int n, int& comparision);
void merge(int* arr, int left, int mid, int right, int& comparision);
void mergeSort(int* arr, int left, int right, int& comparision);
void quickSort(int* arr, int left, int right, int& comparision);
#endif