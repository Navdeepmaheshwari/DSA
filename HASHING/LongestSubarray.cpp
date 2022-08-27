#include <bits/stdc++.h>
using namespace std;

//****Naive Solution****//
// Time-O(n2);
// Space-O(1);
int maxlenNaive(int arr[], int n, int sum)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int cur_sum = 0;
        for (int j = i; j < n; j++)
        {
            cur_sum += arr[j];
            if (cur_sum == sum)
            {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}

// Efficient solution
// O(n)-Time
// O(n)-Space
int maxlen(int arr[], int n, int sum)
{
    unordered_map<int, int> m;
    int pre_sum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == sum)
            res = i + 1;
        if (m.find(pre_sum) == m.end())
        {
            m.insert({pre_sum, i});
        }
        if (m.find(pre_sum - sum) != m.end())
        {
            res = max(res, i - m[pre_sum - sum]);
        }
    }
    return res;
}
int main()
{
    int arr[] = {8, 3, 1, 5, -6, 6, 2, -2};
    int sum = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = maxlenNaive(arr, n, sum);
    // int ans = maxlen(arr, n, sum);
    cout << ans << endl;
    return 0;
}
