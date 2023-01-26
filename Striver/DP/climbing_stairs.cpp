#include <bits/stdc++.h>
using namespace std;

/*
Method-1
! Memoization Method
* TC-O(N)
* SC-O(N)+O(N)
*/
int climbingStairs1(int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n < 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = climbingStairs1(n - 1, dp) + climbingStairs1(n - 2, dp);
}

/*
Method-2
! Tabulation Method
* TC-O(N)
* SC-O(N)
*/
int climbingStairs2(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

/*
Method-3
! Space Optimization Method
* TC-O(N)
* SC-1
*/
int climbingStairs3(int n)
{
    // vector<int> dp(n + 1, -1);
    // dp[0] = 1;
    int prev2 = 1;
    // dp[1] = 1;
    int prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        // dp[i] = dp[i - 1] + dp[i - 2];
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
int main()
{

    int n = 45;
    vector<int> dp(n + 1, -1);
    int ans1 = climbingStairs1(n, dp);
    int ans2 = climbingStairs2(n);
    int ans3 = climbingStairs2(n);
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
    return 0;
}