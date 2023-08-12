class Solution {
public:
    int path(int row,int col, vector<vector<int>>&dp,vector<vector<int>>& obs)
    {
       
        if(row<0||col<0)return 0;
        if(obs[row][col])return dp[row][col]=0;
         if(row==0&&col==0)return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        
        int up=path(row-1,col,dp,obs);
        int left=path(row,col-1,dp,obs);
        
        return dp[row][col]= up+left;
        
    }  
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)     {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return path(m-1,n-1,dp,obstacleGrid);
    }
};