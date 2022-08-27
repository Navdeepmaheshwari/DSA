/*
Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.

Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
*/

#include <bits/stdc++.h>
using namespace std;

// NAIVE SOLUTION
// Time--O(n2)
// Space--O(1)
void printNextGreaterN(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                cout << arr[j] << " ";
                break;
            }
        }
        if (j == n)
        {
            cout << -1 << " ";
        }
    }
}

// EFFICEINT SOLUTION
// Time--O(n)
// Space--O(n)
vector<int> printNextGreaterE(int arr[], int n)
{
    vector<int> ans;
    stack<int> s;
    s.push(arr[n - 1]);
    ans.push_back(-1);
    // cout << -1 << " ";
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && s.top() <= arr[i])
        {
            s.pop();
        }

        int nextGreater = s.empty() ? -1 : s.top();
        // cout << nextGreater << " ";
        ans.push_back(nextGreater);
        s.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{
    vector<int> ans;
    int arr[] = {5, 15, 10, 8, 6, 12, 9, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNextGreaterN(arr, n);
    cout << endl;
    ans = printNextGreaterE(arr, n); // efficinet method print output in reverse order so return as vector
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}