#include <bits/stdc++.h>
using namespace std;

// EFFICEINT SOLUTION
// Time--O(n)
// Space--O(n)
vector<int> printNextSmallE(int arr[], int n)
{
    vector<int> ans;
    stack<int> s;
    s.push(arr[n - 1]);
    ans.push_back(-1);
    // cout << -1 << " ";
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && s.top() >= arr[i])
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
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    ans = printNextSmallE(arr, n); // efficinet method print output in reverse order so return as vector
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}