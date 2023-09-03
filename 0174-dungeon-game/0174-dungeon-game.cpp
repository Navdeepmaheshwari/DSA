class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,int m,int n, vector<vector<int>>&dp){
        if(i>=m||j>=n)return 1e7;
        if(i==m-1&&j==n-1){
            if(grid[i][j]>0){
                return dp[i][j]=1;
            }
            else{
                return dp[i][j]=abs(grid[i][j])+1  ;
            }    
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        //2case
        int right=solve(i,j+1,grid,m,n,dp);
        int bottom=solve(i+1,j,grid,m,n,dp);
        
        int minHealth=min(right,bottom)-grid[i][j];
        
       return dp[i][j]=(minHealth>0)?minHealth:1;
        
    }
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,grid,m,n,dp);
    }
};