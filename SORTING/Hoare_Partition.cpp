#include <bits/stdc++.h>
using namespace std;
int HPartition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true)
    {
        // Find leftmost element greater than
        // or equal to pivot
        do
        {
            i++;
        } while (arr[i] < pivot);

        // Find rightmost element smaller than
        // or equal to pivot
        do
        {
            j--;
        } while (arr[j] > pivot);

        // If two pointers met.
        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int pIndex = HPartition(arr, 0, n - 1);
    cout << pIndex << endl;
}
