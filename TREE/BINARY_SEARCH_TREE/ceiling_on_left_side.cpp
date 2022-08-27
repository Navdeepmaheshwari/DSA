/*
    *Given an Array ,
    we have to find the ceiling of element (Smallest Greater Element) for ith element.
    Print(-1) if not present
*/

#include <bits/stdc++.h>
using namespace std;

void findCeiling(int arr[], int n)
{
    cout << -1 << " ";
    set<int> s;
    s.insert(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (s.lower_bound(arr[i]) != s.end())
        {
            cout << *(s.lower_bound(arr[i])) << " ";
        }
        else
        {
            cout << -1 << " ";
        }

        s.insert(arr[i]);
    }
    cout << endl;
}

int main()
{

    int arr[] = {2, 8, 30, 15, 25, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    findCeiling(arr, n);
}