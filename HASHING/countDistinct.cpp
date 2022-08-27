#include <bits/stdc++.h>
using namespace std;
//Time-O(n);
//Space-O(n);
int countDistinct(int arr[], int n)
{
    unordered_set<int> num;
    for (int i = 0; i < n; i++)
    {
        num.insert(arr[i]);
    }
    return num.size();
}
int main()
{
    int arr[] = {10, 20, 10, 30, 40, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = countDistinct(arr, n);
    cout << ans << endl;
}