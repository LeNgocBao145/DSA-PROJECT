#include <iostream>

using namespace std;

//Thuật toán sắp xếp cocktail sort hay còn gọi là shaker sort (là bubble sort 2 chiều xuôi và ngược)
void shakerSort(int* arr[], int n);

//Thuật toán shell sort sử dụng gap là n/2 cho mỗi bước sort để chia thành nhiều sub - arrays nhỏ qua 
//mỗi lần chia thì gap /= 2 và sort bằng insertion sort
void shellSort(int* arr[], int n);