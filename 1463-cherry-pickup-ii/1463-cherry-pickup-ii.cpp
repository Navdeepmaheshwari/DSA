class Solution {
public:
    int dfs(int i,int j1,int j2,vector<vector<int>>& grid,int m,int n,vector<vector<vector<int>>>&dp){
        
        if(i<0||i>=m||j1<0||j1>=n||j2<0||j2>=n)return -1e8;
        if(i==m-1){
            
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int mx=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++){
            
            for(int dj2=-1;dj2<=1;dj2++){
                int res=0;
                if(j1==j2){
                    res=grid[i][j1];
                }
                else{
                    res=grid[i][j1]+grid[i][j2];
                }
                res+=dfs(i+1,j1+dj1,j2+dj2,grid,m,n,dp);
                mx=max(mx,res);
            }
        }
        return dp[i][j1][j2]= mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //3D-DP
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));

        return dfs(0,0,n-1,grid,m,n,dp);
    }
};