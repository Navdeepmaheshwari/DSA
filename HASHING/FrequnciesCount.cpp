#include <bits/stdc++.h>
using namespace std;
// Time-O(n);
// Space-O(n);
int countFreuenc(int arr[], int n)
{
    unordered_map<int, int> num;
    for (int i = 0; i < n; i++)
    {
        num[arr[i]]++;
    }

    for (auto e : num)
    {
        cout << e.first << " " << e.second <<endl;
    }
    return 0;
}
int main()
{
    int arr[] = {10, 20, 10, 30, 40, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreuenc(arr, n);
}