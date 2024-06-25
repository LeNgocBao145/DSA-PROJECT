#include <iostream>

using namespace std;

void shakerSort(int* arr[], int n)
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

void shellSort(int* arr[], int n)
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