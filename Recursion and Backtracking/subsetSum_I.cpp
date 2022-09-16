/*
TODO:-Given an array print all the sum of the subset generated from it, in the increasing order.
*/
#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(2^n)+O(2^n log(2^n)).for n index Time complexity for O(2^n) and for sorting it will take (2^n log(2^n))
Space Complexity:O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
*/
void sumRec(vector<int> arr, int n, int ind, int sum, vector<int> &allSum)
{
    if (ind == n)
    {
        allSum.push_back(sum);
        return;
    }

    //* Not pick Condition
    sumRec(arr, n, ind + 1, sum, allSum);

    //* Pick Condition
    sumRec(arr, n, ind + 1, sum + arr[ind], allSum);
}
vector<int> subsetSum(vector<int> arr, int n)
{
    vector<int> allSum;

    //* initially ind=0 and sum=0
    int ind = 0, sum = 0;
    sumRec(arr, n, ind, sum, allSum);
    sort(allSum.begin(), allSum.end());
    return allSum;
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> ans;
    ans = subsetSum(arr, arr.size());
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}