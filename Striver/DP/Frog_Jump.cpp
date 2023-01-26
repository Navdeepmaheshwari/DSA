// Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
#include <bits/stdc++.h>
using namespace std;

/* Method - 1 (Fails at large values of n)
 ! Recursion Method
 * TC - O(N)

*/
int f1Rec(int i, vector<int> heights)
{
    if (i == 0)
        return 0;
    int left = f1Rec(i - 1, heights) + abs(heights[i] - heights[i - 1]);
    int right = INT_MAX;

    if (i > 1)
    {
        right = f1Rec(i - 2, heights) + abs(heights[i] - heights[i - 2]);
    }
    return min(left, right);
}
int frogJump1(int n, vector<int> &heights)
{
    // we take from 0 to n-1 so last index is n-1;
    return f1Rec(n - 1, heights);
}

/* Method - 2
 ! Memoization Method
 * TC - O(N)
 * SC - O(N) + O(N)
*/
int f2Rec(int i, vector<int> heights, vector<int> &dp)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int left = f2Rec(i - 1, heights, dp) + abs(heights[i] - heights[i - 1]);
    int right = INT_MAX;

    if (i > 1)
    {
        right = f2Rec(i - 2, heights, dp) + abs(heights[i] - heights[i - 2]);
    }
    return dp[i] = min(left, right);
}
int frogJump2(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    // we take from 0 to n-1 so last index is n-1;
    return f2Rec(n - 1, heights, dp);
}

/* Method - 3
 ! Tabulation Method
 * TC - O(N)
 * SC - O(N)
*/

int frogJump3(int n, vector<int> &heights)
{

    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {

        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;

        if (i > 1)
        {
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}

int main()
{
    vector<int> heights = {7, 4, 4, 2, 6, 6, 3, 4};
    int n = heights.size();
    // int ans1 = frogJump1(n, heights);
    int ans1 = frogJump2(n, heights);
    cout << ans1 << endl;
    return 0;
}