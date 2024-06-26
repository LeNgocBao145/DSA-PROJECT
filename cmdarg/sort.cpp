#include <iostream>

#include "sort.h"
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


void shakerSort(int* arr, int n, int &comparision)
{
    comparision = 0;

    int head = 0;
    int tail = n - 1;

    while(++comparision && (head < tail))
    {
        for(int i = head; ++comparision && (i < tail); i++)
        {
            if(++comparision && (arr[i] > arr[i + 1]))
            {
                swap(arr[i], arr[i + 1]);
            }
        }

        for(int i = tail - 1; ++comparision && (i > head); i--)
        {
            if(++comparision && (arr[i] < arr[i - 1]))
            {
                swap(arr[i], arr[i - 1]);
            }
        }

        head++;
        tail--;
    }
}

void shellSort(int* arr, int n, int &comparision)
{
    comparision = 0;

    int gap = n / 2;

    while(++comparision && gap != 0)
    {
        for(int i = 0; ++comparision && (i < n); i++)
        {
            int index = i;
            int temp = arr[i];
            while(++comparision && temp < arr[index - gap] && index - gap >= 0)
            {
                arr[index] = arr[index - gap];
                index -= gap;
            }

            arr[index] = temp;
        }


        gap /= 2;
    } 
}

int* countingSort(int* arr, int n, int& comparision, double& time) {
    int max = arr[0];
    int min = arr[0];
    int* res = new int[n];
    for (int i = 0; i < n; i++) {
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }

    if (min < 0) {
        for (int i = 0; i < n; i++) {
            arr[i] += -min;
        }
        max = arr[0];
        for (int i = 0; i < n; i++) {
            if (max < arr[i])
                max = arr[i];
        }
    }

    int* count = new int[max + 1];
    for (int i = 0; i < max + 1; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        res[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    if (min < 0) {
        for (int i = 0; i < n; i++) {
            res[i] += min;
        }
    }

    delete[] count;
    count = NULL;

    return res;
}

// This part is for flash sort
int get_bucket_id(int value, int n_buckets,
    int min, int max) {
    return ((n_buckets - 1) * (int)((value - min) / (max - min)));
}
int find_swap_index(int* arr, int* buckets, int n_buckets,
    int min, int max, int b_id) {
    int i = 0;
    for (i = buckets[b_id - 1]; i < buckets[b_id]; i++) {
        if (get_bucket_id(arr[i], n_buckets, min, max) != b_id) {
            break;
        }
    }

    return i;
}
void arrange_bucket(int* arr, int* buckets, int left, int right, int b,
    int max, int min, int n_buckets) {


    for (int i = left; i < right; i++) {
        int b_id = get_bucket_id(arr[i], n_buckets, min, max);
        while (b != b_id) {
            int swap_index = find_swap_index(arr, buckets, n_buckets, min, max, b_id);
            int temp = arr[i];
            arr[i] = arr[swap_index];
            arr[swap_index] = temp;
            b_id = get_bucket_id(arr[i], n_buckets, min, max);
        }

    }
}

void insertion_sort(int*& arr, int left, int right) {
    for (int i = left + 1; i < right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


int* flashSort(int* arr, int n, int& comparision, double& time) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < n; i++) {
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }

    int n_buckets = (int)(0.45 * n);
    if (n_buckets <= 1) n_buckets = 1;

    int* buckets = new int[n_buckets];
    for (int i = 0; i < n_buckets; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        buckets[get_bucket_id(arr[i], n_buckets, min, max)]++;
    }

    for (int i = 1; i < n_buckets; i++) {
        buckets[i] += buckets[i - 1];
    }

    for (int b = 0; b < n_buckets - 1; b++) {
        if (b == 0) {
            arrange_bucket(arr, buckets, 0, buckets[0], 0, max, min, n_buckets);
        }
        else {
            arrange_bucket(arr, buckets, buckets[b - 1], buckets[b], b, max, min, n_buckets);
        }
    }

    for (int b = 0; b < n_buckets; b++) {
        if (b == 0) {
            insertion_sort(arr, 0, buckets[0]);
        }
        else {
            insertion_sort(arr, buckets[b - 1], buckets[b]);
        }
    }

    delete[] buckets;
    buckets = NULL;
}

void radixSort(int *arr, int n, int &comparision)
{
    comparision = 0;

    //Tìm phần tử lớn nhất
    int max = arr[0];
    int min = arr[0];
    for(int i = 0; ++comparision && (i < n); i++)
    {
        if(++comparision && (max < arr[i]))
        {
            max = arr[i];
        }else if(++comparision && (min > arr[i])){
            min = arr[i];
        }
    }

    int countPos = 0;
    int countNeg = 0;
    int* negatives = new int[n];
    int* positives = new int[n];

    for(int i = 0; ++comparision && (i < n); i++)
    {
        if(++comparision && arr[i] < 0)
        {
            negatives[countNeg++] = abs(arr[i]);
        }else
        {
            positives[countPos++] = arr[i];
        }
    }
    
    int divid = 1;

    if(++comparision && countNeg != 0)
    {
        while(++comparision && abs(min) / divid > 0)
        {

            int *ans = new int[countNeg];
            int exist[10] = {0};

            for(int i = 0; ++comparision && i < countNeg; i++)
            {
                int index = (negatives[i] / divid) % 10;
                exist[index]++;
            }

            //Tính mảng cộng dồn để đếm số phần tử xuất hiện và vị trí của chúng
            for(int i = 1; ++comparision && i < 10; i++)
            {
                exist[i] += exist[i - 1];
            }


            //Gán và sắp xếp các phần tử vào mảng phụ
            for(int i = countNeg - 1; ++comparision && i >= 0; i--)
            {
                int index = (negatives[i] / divid) % 10;
                ans[exist[index] - 1] = negatives[i];
                exist[index]--;
            }

            //Gán phần tử kết quả vào mảng chính
            int index = 0;

            for(int i = 0; ++comparision && i < countNeg; i++)
            {
                negatives[i] = ans[i]; 
            }

            divid *= 10;
            delete[] ans;
        }
    }

    divid = 1;

    if(++comparision && countPos > 0)
    {
        while(++comparision && max / divid > 0)
        {

            int *ans = new int[countPos];
            int exist[10] = {0};

            for(int i = 0; ++comparision && i < countPos; i++)
            {
                int index = (positives[i] / divid) % 10;
                exist[index]++;
            }

            //Tính mảng cộng dồn để đếm số phần tử xuất hiện và vị trí của chúng
            for(int i = 1; ++comparision && i < 10; i++)
            {
                exist[i] += exist[i - 1];
            }


            //Gán và sắp xếp các phần tử vào mảng phụ
            for(int i = countPos - 1; ++comparision && i >= 0; i--)
            {
                int index = (positives[i] / divid) % 10;
                ans[exist[index] - 1] = positives[i];
                exist[index]--;
            }

            //Gán phần tử kết quả vào mảng chính
            for(int i = 0; ++comparision && i < countPos; i++)
            {
                positives[i] = ans[i]; 
            }

            divid *= 10;
            delete[] ans;
        }
    }

    int index = 0;

    if(++comparision && countNeg != 0)
    {
        for(int i = countNeg - 1; ++comparision && i >= 0; i--)
        {
            arr[index] = (-1) * negatives[i];
            index++;
        }
    }

    if(++comparision && countPos != 0)
    {
        for(int i = 0; ++comparision && i < countPos; i++)
        {
            arr[countNeg + i] = positives[i];
        }
    }
}