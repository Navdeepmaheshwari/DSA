#include <bits/stdc++.h>
using namespace std;
int srch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
        
    }
    return -1;
}
int main()
{
    int N = 5;
    int arr[] = {1, 2, 3, 7, 9};
    int x = 17; // value we want to search

    int n = sizeof(arr) / sizeof(arr[0]);
    // cout<<sizeof(arr)/sizeof(arr[0])<<endl;

    int index = srch(arr, n, x);
    cout << "Element " << x << " Found at Index:" << index << endl;

    return 0;
}