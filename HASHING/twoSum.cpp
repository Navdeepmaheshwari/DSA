#include <bits/stdc++.h>
using namespace std;
// Time-O(n);
// Space-O(n);
bool sum(int arr[], int n, int x)
{
    unordered_set<int> num;
    for (int i = 0; i < n; i++)
    {
        if (num.find(x - arr[i]) != num.end())
        {
            return true;
        }
        num.insert(arr[i]);
    }
    return false;
}
int main()
{
    int arr[] = {11,4,6};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    bool ans = sum(arr, n, x);
    cout << ans << endl;
}