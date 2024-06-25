#include <iostream>

using namespace std;

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