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
void rightRotate(int arr[], int n)
{
    int temp=arr[n-1];
    for (int i = n-1; i >0; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
    
}
int main()
{
    int N = 5;
    int arr[] = {1, 2, 3, 7, 9};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Array : ";
    printArray(arr, n);
    rightRotate(arr, n);
    cout<<"Right Rotate Array : ";
    printArray(arr, n);
    return 0;
}