#include <bits/stdc++.h>
using namespace std;

void findUnion(int arr1[], int arr2[])
{
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    set<int> s;
    for (int i = 0; i < n1; i++)
    {
        s.insert(arr1[i]);
    }
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    for (int i = 0; i < n2; i++)
    {
        s.insert(arr2[i]);
    }

    for (auto it = s.begin(); it !=
                              s.end();
         ++it)
        cout << *it << " ";
}
void intersection(int arr1[], int arr2[])
{
    set<int> s;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    for (int i = 0; i < n1; i++)
        s.insert(arr1[i]);

    for (int i = 0; i < n2; i++)
    {
        if (s.find(arr2[i]) != s.end())
            cout << arr2[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    int arr2[] = {5, 6};
}