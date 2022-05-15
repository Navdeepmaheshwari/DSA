// Count the freuencies in Sorted Array
#include <bits/stdc++.h>
using namespace std;
void printFreq(int arr[], int n)
{
    int freq = 1, i = 1;
    while (i < n)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            freq++;
            i++;
        }
        cout << arr[i - 1] << " --> " << freq << endl;
        i++;
        freq = 1;
    }
    if (arr[n - 1] != arr[n - 2] || n == 1)
    {
        cout << arr[n - 1] << " --> " << 1 << endl;
    }
}
int main()
{
    // int N = 5;
    // Sorted array
    // int arr[] = {40,40,  50, 50, 50};
    int arr[] = {10, 10, 10, 30, 30, 40};

    int n = sizeof(arr) / sizeof(arr[0]);
    printFreq(arr, n);
    return 0;
}