#include <bits/stdc++.h>
using namespace std;
void Merge(int arr[], int low, int mid, int high)
{
    // Setting Auxillary Arrays
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[n1 + i];
    }
    // Merge Sort Logic
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[], int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);

        MergeSort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {10, 5, 30, 15, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << n << endl;
    cout << "Before Merge Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    int l = 0;
    int r = n - 1;
    cout << endl;
    cout << "After Merge Sorting" << endl;
    MergeSort(arr, l, r);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}