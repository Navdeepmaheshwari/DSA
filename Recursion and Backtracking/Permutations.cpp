/*
Todo- Given an array arr of distinct integers, print all permutations of Array.
*/
#include <bits/stdc++.h>
using namespace std;

/*
! Approach-1
Time Complexity:  O(N! x N)
Space Complexity:  O(N) use Extra Space
*/
void RecfindPermutation_1(vector<int> arr, vector<int> &ds, vector<vector<int>> &res, int freq[])
{
    if (ds.size() == arr.size())
    {
        res.push_back(ds);
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {

        if (!freq[i])
        {
            ds.push_back(arr[i]);
            freq[i] = 1;
            RecfindPermutation_1(arr, ds, res, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> findPermutation_1(vector<int> arr)
{
    vector<vector<int>> res;
    vector<int> ds;
    int freq[arr.size()] = {0};
    RecfindPermutation_1(arr, ds, res, freq);
    return res;
}

/*
! Approach-2 - With Backtracking
Time Complexity:  O(N! x N)
Space Complexity:  O(1) No Extra Space
*/
void RecfindPermutation_2(vector<int> arr, int index, vector<vector<int>> &res)
{
    if (index == arr.size())
    {
        res.push_back(arr);
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {

        swap(arr[i], arr[index]);

        RecfindPermutation_2(arr, index + 1, res);

        swap(arr[i], arr[index]);
    }
}
vector<vector<int>> findPermutation_2(vector<int> arr)
{
    vector<vector<int>> res;
    int index = 0;
    RecfindPermutation_2(arr, index, res);
    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> ans;
    ans = findPermutation_2(arr);
    for (auto i : ans)
    {
        cout << "{ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "}";
        cout << endl;
    }
    return 0;
}