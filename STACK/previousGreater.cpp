/*
Given an array arr[ ] of size N having distinct elements,
the task is to find the previous greater element for each element

Previous greater element of an element in the array is the nearest element
on the Left which is greater than the current element.
*/
#include <bits/stdc++.h>
using namespace std;

// NAIVE SOLUTION
// Time--O(n2)
// Space--O(1)
void printPrevGreaterN(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                cout << arr[j] << " ";
                break;
            }
        }
        if (j == -1)
        {
            cout << -1 << " ";
        }
    }
}

// EFFICEINT SOLUTION
// Time--O(n)
// Space--O()
void printPrevGreaterE(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && s.top() <= arr[i])
        {
            s.pop();
        }

        int prevGreater = s.empty() ? -1 : s.top();
        cout << prevGreater << " ";
        s.push(arr[i]);
    }
}
int main()
{
    int arr[] = {100, 80, 60, 70, 160, 75, 185};
    int n = sizeof(arr) / sizeof(arr[0]);
    // printPrevGreaterN(arr, n);
    printPrevGreaterE(arr, n);
}