/*
Todo- Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.                                           Each number in candidates may only be used once in the combination
*/

#include <bits/stdc++.h>
using namespace std;
void combinationRec(vector<int> arr, int ind, int target, vector<vector<int>> &res, vector<int> &ds)
{

    if (target == 0)
    {
        res.push_back(ds);
        return;
    }

    // pick up Element
    for (int i = ind; i < arr.size(); i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        combinationRec(arr, i + 1, target - arr[i], res, ds);
        ds.pop_back();
    }
}
vector<vector<int>> findCombination(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    vector<int> ds;
    int ind = 0;
    combinationRec(arr, ind, target, res, ds);
    return res;
}
int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
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