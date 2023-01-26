/*
?LEETCODE-658. Find K Closest Elements
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({abs(arr[i] - x), arr[i]});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> res;

    while (pq.empty() == false)
    {

        res.push_back(pq.top().second);
        pq.pop();
    }
    sort(res.begin(), res.end());
    return res;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;
    vector<int> ans = findClosestElements(arr, k, x);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}