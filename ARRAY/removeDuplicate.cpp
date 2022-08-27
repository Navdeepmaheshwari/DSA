// O(N)-Time and O(1)-Space
#include <bits/stdc++.h>
using namespace std;
int removeDuplicate(int arr[], int n)
{
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[res - 1])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array  : ";
    printArray(arr, n);

    n = removeDuplicate(arr, n);
    cout << "After Remove Duplicate Element Array : ";
    printArray(arr, n);
    return 0;
}