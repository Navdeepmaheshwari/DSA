#include <bits/stdc++.h>
using namespace std;

//* function to sort according to value/weight ratios
bool myfunc(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.first / (double)a.second;
    double r2 = (double)b.first / (double)b.second;
    return r1 > r2;
}
double fractionalKnapsack(vector<pair<int, int>> arr, int W)
{
    sort(arr.begin(), arr.end(), myfunc);
    double res = 0.0;
    int curr_cap = W;
    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i].second <= curr_cap)
        {
            curr_cap -= arr[i].second;
            res += arr[i].first;
        }
        else
        {
            res += arr[i].first * ((double)curr_cap / (double)arr[i].second);
            break;
        }
    }
    return res;
}
int main()
{
    //* pair(value,weight)
    vector<pair<int, int>> arr = {{120, 30}, {60, 10}, {100, 20}};
    int W = 50;
    // cout << arr.size();
    double ans = fractionalKnapsack(arr, W);
    cout << ans << endl;
    return 0;
}