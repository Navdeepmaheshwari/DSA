#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void permutation(vector<int> &ds, map<int, int> mp, vector<int> arr)
{
    if (ds.size() == arr.size())
    {
        res.push_back(ds);
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {

        if (!mp[i])
        {
            ds.push_back(arr[i]);
            mp[i] = 1;
            permutation(ds, mp, arr);
            mp[i] = 0;
            ds.pop_back();
        }
    }
}

void permut(int ind, vector<int> arr)
{

    if (ind == arr.size())
    {
        res.push_back(arr);
    }

    for (int i = ind; i < arr.size(); i++)
    {

        swap(arr[ind], arr[i]);
        permut(ind + 1, arr);
        swap(arr[ind], arr[i]);
    }
}
int main()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[i] = 0;
    }
    vector<int> ds;
    // permutation(ds, mp, arr); //Approach-1

    permut(0, arr);
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