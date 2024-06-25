#ifndef SORT_H
#define SORT_H
#include <iostream>
using namespace std;
void heapify(int* arr, int n, int i, int& comparision);
void heapSort(int* arr, int n, int& comparision);
void merge(int* arr, int left, int mid, int right, int& comparision);
void mergeSort(int* arr, int left, int right, int& comparision);
void quickSort(int* arr, int left, int right, int& comparision);

//Thuật toán sắp xếp cocktail sort hay còn gọi là shaker sort (là bubble sort 2 chiều xuôi và ngược)
void shakerSort(int arr[], int n);

//Thuật toán shell sort sử dụng gap là n/2 cho mỗi bước sort để chia thành nhiều sub - arrays nhỏ qua 
//mỗi lần chia thì gap /= 2 và sort bằng insertion sort
void shellSort(int arr[], int n);

int* countingSort(int* arr, int n, int& comparision, double& time);
int* flashSort(int* arr, int n, int& comparision, double& time);
#endif
