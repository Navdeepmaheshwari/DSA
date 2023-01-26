#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;

void combinationSum(int ind, vector<int> &arr, int target, vector<int> &ans)
{
    if (ind >= arr.size())
    {
        if (target == 0)
        {
            res.push_back(ans);
        }
        return;
    }

    if (arr[ind] <= target)
    {
        ans.push_back(arr[ind]);
        combinationSum(ind, arr, target - arr[ind], ans);
        ans.pop_back();
    }
    combinationSum(ind + 1, arr, target, ans);
}
int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;
    vector<int> ans;
    combinationSum(0, arr, target, ans);
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
 
}