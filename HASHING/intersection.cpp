#include <bits/stdc++.h>
using namespace std;

int intersection(int arr1[], int arr2[], int n1, int n2)
{
    unordered_set<int> num1, num;
    for (int i = 0; i < n1; i++)
    {
        num1.insert(arr1[i]);
    }
    int res = 0;
    for (int j = 0; j < n2; j++)
    {
        if (num1.find(arr2[j]) != num1.end())
        {
            res++;
            num.insert(arr2[j]);
            num1.erase(arr2[j]);
        }
    }
    cout << "Total Intersection Element:" << res << endl;
    for (int i : num)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
int main()
{
    int arr1[] = {10, 20, 10, 30, 40, 20}; // unsorted
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {10, 20, 10, 30}; // unsorted
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    intersection(arr1, arr2, n1, n2);
    // cout << ans << endl;
}