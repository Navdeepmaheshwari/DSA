#include <bits/stdc++.h>
using namespace std;

vector<int> closestNumbers(vector<int> arr)
{
    vector<int> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];
    ans.push_back(arr[0]);
    ans.push_back(arr[1]);
    for (int i = 2; i < n; i++)
    {
        int res = arr[i] - arr[i - 1];
        if (diff > res)
        {
            diff = res;
            ans.clear();
            ans.push_back(arr[i - 1]);
            ans.push_back(arr[i]);
        }
        else if (res == diff)
        {
            ans.push_back(arr[i - 1]);
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
int main()
{

    vector<int> arr = {-20, -3916237, -357920, -3620601, -7330761, 30, 6246457, -6461594, 266854, -520, -470};
    // vector<int> arr = {1, 2, 10, 20};
    vector<int> ans = closestNumbers(arr);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}