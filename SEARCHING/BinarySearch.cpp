// Binary Search
#include <bits/stdc++.h>
using namespace std;
// Iterative Method
int binarySearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// Recursive Method
int recursiveBinarySearch(int arr[], int low, int high, int x)
{

    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] > x)
    {
        return recursiveBinarySearch(arr, low, mid - 1, x);
    }
    else
    {
        return recursiveBinarySearch(arr, mid + 1, high, x);
    }
}
int main()
{

    int arr[] = {10, 20, 30, 40, 50, 60, 70}; // Sorted Array

    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 25; // element we want to search
    // int pos = binarySearch(arr, n, x);
    int low = 0, high = n - 1;
    int pos = recursiveBinarySearch(arr, low, high, x);
    cout << "Element " << x << " is present at index " << pos << endl;
    return 0;
}