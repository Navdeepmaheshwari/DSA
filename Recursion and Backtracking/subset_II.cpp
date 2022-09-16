/*
TODO-  Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.
*/

#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity:O(k * 2^n)
O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n)  .

Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.
*/
void findSubsetRec(vector<int> arr, int ind, vector<vector<int>> &res, vector<int> &ds)
{
    res.push_back(ds);
    for (int i = ind; i < arr.size(); i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        findSubsetRec(arr, i + 1, res, ds);
        ds.pop_back();
    }
}
vector<vector<int>> subset(vector<int> arr, int n)
{
    vector<vector<int>> res;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    int ind = 0;
    findSubsetRec(arr, ind, res, ds);
    return res;
}
int main()
{
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> ans;
    ans = subset(arr, arr.size());
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