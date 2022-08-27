#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void reverseArray(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int temp;
        // swapping low and hifh element
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}
int main()
{
    int N = 5;
    int arr[] = {1, 2, 3, 7, 9};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Array : ";
    printArray(arr, n);
    reverseArray(arr, n);
    cout<<"Reverse Array : ";
    printArray(arr, n);
    return 0;
}