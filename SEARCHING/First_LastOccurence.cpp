#include <bits/stdc++.h>
using namespace std;

// FIRST OCCURENCE
int firstOcc(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            if (mid == 0 || arr[mid] != arr[mid - 1])
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// LAST OCCURENCE
int lastOcc(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            if (mid == n - 1 || arr[mid] != arr[mid + 1])
            {
                return mid;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}
// NO OF OCCURNECE
int countOcc(int arr[], int n, int x)
{
    int first = firstOcc(arr, n, x);
    if (first == -1)
        return 0;
    else
        return (lastOcc(arr, n, x) - first + 1);
}
int main()
{

    int arr[] = {5, 10, 10, 10, 10, 20, 20}; // Sorted Array

    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5; // element we want to search
    int fpos = firstOcc(arr, n, x);
    int lpos = lastOcc(arr, n, x);
    cout << "Element " << x << " First Occurence at index " << fpos << endl;
    cout << "Element " << x << " Last Occurence at index " << lpos << endl;
    cout << "Element " << x << " Occured " << countOcc(arr, n, x) << endl;
    return 0;
}