// In frog jump question frog jump to either to 1 or 2 setps but in this Question frog can be jump to 1 or 2 or 3.....or k steps
#include <bits/stdc++.h>
using namespace std;

/* Method - 1 (Fails at large values of n)
 ! Recursion Method
 * TC - O(N)

*/
int f1Rec(int i, vector<int> heights, int k)
{
    if (i == 0)
        return 0;
    int minjump = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 0)
        {
            int currjump = f1Rec(i - j, heights, k) + abs(heights[i] - heights[i - j]);
            minjump = min(minjump, currjump);
        }
    }
    return minjump;
}
int frogJump1(int n, vector<int> &heights, int k)
{
    // we take from 0 to n-1 so last index is n-1;
    return f1Rec(n - 1, heights, k);
}

/* Method - 2
 ! Memoization Method
 * TC - O(N)
 * SC - O(N) + O(N)
*/
int f2Rec(int i, vector<int> heights, vector<int> &dp, int k)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int minjump = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 0)
        {
            int currjump = f2Rec(i - j, heights, dp, k) + abs(heights[i] - heights[i - j]);
            minjump = min(minjump, currjump);
        }
    }
    return dp[i] = minjump;
}
int frogJump2(int n, vector<int> &heights, int k)
{
    vector<int> dp(n + 1, -1);
    // we take from 0 to n-1 so last index is n-1;
    return f2Rec(n - 1, heights, dp, k);
}
int main()
{

    vector<int> heights = {30, 10, 60, 10, 60, 50};
    int n = heights.size();
    int k = 2;
    int ans1 = frogJump1(n, heights, k);
    // int ans1 = frogJump2(n, heights, k);
    cout << ans1 << endl;
    return 0;
}