#include <bits/stdc++.h>
using namespace std;

int union_array(int arr1[], int arr2[], int n1, int n2)
{
    unordered_set<int> num1;
    for (int i = 0; i < n1; i++)
    {
        num1.insert(arr1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        num1.insert(arr2[i]);
    }
    // sort(num1.begin(), num1.end());
    cout << "Total Union Element:" << num1.size() << endl;
    for (int i : num1)
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
    int arr2[] = {10, 20, 10, 30,60}; // unsorted
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    union_array(arr1, arr2, n1, n2);
    // cout << ans << endl;
}