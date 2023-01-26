#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void subseqWithSum(int index, vector<int> &arr, vector<int> &ans, int sum, int k)
{
    if (index >= arr.size())
    {

        if (sum == k)
        {
            res.push_back(ans);
        }
        return;
    }

    ans.push_back(arr[index]);
    sum += arr[index];
    subseqWithSum(index + 1, arr, ans, sum, k);
    sum -= arr[index];
    ans.pop_back();

    subseqWithSum(index + 1, arr, ans, sum, k);
}
int main()
{
    vector<int> arr = {1, 2, 1};
    int k = 2;
    vector<int> ans;
    subseqWithSum(0, arr, ans, 0, k);
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