class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& tri,int n, vector<vector<int>>&dp){
        if(row==n)return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        int first=tri[row][col]+solve(row+1,col,tri,n,dp);
        int second=tri[row][col]+solve(row+1,col+1,tri,n,dp);
        
        return dp[row][col]=min(first,second);

    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,tri,n,dp);
    }
};