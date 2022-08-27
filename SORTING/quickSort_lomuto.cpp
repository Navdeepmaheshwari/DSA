#include <bits/stdc++.h>
using namespace std;
int LPartition(int arr[], int l, int h)
{
    int p = arr[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < p)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}
void qSort(int arr[], int l, int h)
{
    if (l < h)
    {

        int pIndex = LPartition(arr, l, h);
        qSort(arr, l, pIndex - 1);
        qSort(arr, pIndex, h);
    }
}
int main()
{
    int arr[] = {8, 4, 7, 9, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before quick Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "After quick Sorting" << endl;
    qSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // cout << pIndex << endl;
}