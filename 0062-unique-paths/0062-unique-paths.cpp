class Solution {
public:
    int path(int row,int col,vector<vector<int>>&dp){
        
        if(row==0&&col==0)return 1;
        if(row<0||col<0)return 0;
        
        if(dp[row][col]!=-1)return dp[row][col];
        
        int up=path(row-1,col,dp);
        int left=path(row,col-1,dp);
        
        return dp[row][col]= up+left;
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return path(m-1,n-1,dp);
    }
};