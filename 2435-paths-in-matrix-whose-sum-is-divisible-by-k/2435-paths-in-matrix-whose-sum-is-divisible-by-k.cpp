class Solution {
public:
   int MOD=1e9+7;
    int solve(int i,int j,int sum,vector<vector<vector<int>>>& dp,int k,vector<vector<int>>& grid,int m,int n)
    {
        if(i>=m || j>=n || i<0 || j<0)
            return 0;
        if(i==m-1 && j==n-1)
        {
            sum+=grid[i][j];
            return (sum%k==0);
        }
        if(dp[i][j][sum%k]!=-1)
            return dp[i][j][sum%k];
        
        long long down = solve(i+1,j,sum+grid[i][j],dp,k,grid,m,n);
        long long right = solve(i,j+1,sum+grid[i][j],dp,k,grid,m,n);
        
        return dp[i][j][sum%k]=(down+right)%MOD;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return solve(0,0,0,dp,k,grid,m,n);

    }
};