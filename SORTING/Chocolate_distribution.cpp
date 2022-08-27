#include <bits/stdc++.h>
using namespace std;

int minDiff(int arr[], int m, int n)
{
    if (m > n)
        return -1;
    sort(arr, arr + n);
    int res = arr[m - 1] - arr[0];
    for (int i = 1; i + m - 1 < n; i++)
    {
        res = min(res, (arr[i + m - 1] - arr[i]));
    }
    return res;
}
int main()
{
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41,
                 30, 40, 28, 42, 30, 44, 48,
                 43, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 7;

    int min_difference = minDiff(arr, m, n);
    cout << min_difference << endl;
}