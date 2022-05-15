#include <bits/stdc++.h>
using namespace std;
int linearSearch(int arr[], int n, int x)
{
    int i = 0;
    for (int i = 0; i < n; i++)
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

    int arr[] = {10, 20, 60, 30, 70, 25};

    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 25; // element we want to search
   int pos=linearSearch(arr, n, x);
    cout << "Element " << x << " is present at index " << pos << endl;
    return 0;
}