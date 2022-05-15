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
void leftRotate(int arr[], int n)
{
    int temp=arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    
}
int main()
{
    int N = 5;
    int arr[] = {1, 2, 3, 7, 9};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Array : ";
    printArray(arr, n);
    leftRotate(arr, n);
    cout<<"Left Rotate Array : ";
    printArray(arr, n);
    return 0;
}