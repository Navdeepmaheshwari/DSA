#include <bits/stdc++.h>
using namespace std;
bool mycomp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int mxmAcitivites(vector<pair<int, int>> arr, int n)
{
    sort(arr.begin(), arr.end(), mycomp);
    /*  for (auto i : arr)
     {
         cout << i.first << " " << i.second << endl;
     }
     cout << endl; */
    int res = 1;
    int prev = 0;
    for (int curr = 1; curr < n; curr++)
    {
        if (arr[curr].first >= arr[prev].second)
        {
            res++;
            prev = curr;
        }
    }
    return res;
}
int main()
{
    vector<pair<int, int>> arr = {{3, 8}, {2, 4}, {1, 3}, {10, 11}};
    int n = arr.size();
    int ans = mxmAcitivites(arr, n);
    cout << ans << endl;
    return 0;
}