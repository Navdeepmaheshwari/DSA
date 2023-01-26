/*
Todo-Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.                         The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
*/
#include <bits/stdc++.h>
using namespace std;
void combinationRec(vector<int> arr, int ind, int target, vector<vector<int>> &res, vector<int> &ds)
{
    if (ind == arr.size())
    {
        if (target == 0)
            res.push_back(ds);
        return;
    }

    // pick up Element
    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        combinationRec(arr, ind, target - arr[ind], res, ds);
        ds.pop_back();
    }

    combinationRec(arr, ind + 1, target, res, ds);
}
vector<vector<int>> findCombination(vector<int> arr, int target)
{
    vector<vector<int>> res;
    vector<int> ds;
    int ind = 0;
    combinationRec(arr, ind, target, res, ds);
    return res;
}
int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans;
    ans = findCombination(arr, target);
    for (auto i : ans)
    {
        cout << "[ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}
