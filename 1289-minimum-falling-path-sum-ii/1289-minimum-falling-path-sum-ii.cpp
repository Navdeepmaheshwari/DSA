class Solution {
public:
        int path(int row,int col,vector<vector<int>>& mat,vector<vector<int>>&dp,int n){
        if(row<0||row>=n||col<0||col>=n)return 1e9;
        if(row==n-1)return mat[row][col];
        
        if(dp[row][col]!=-1)return dp[row][col];
        int ans=1e9;
        for(int i=0;i<n;i++){
            if(i==col)continue;
            int curr=path(row+1,i,mat,dp,n)+mat[row][col];
            ans=min(ans,curr);
        }
        
        return dp[row][col]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int ans=1e9;
        int n=mat.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++){
            ans=min(ans,path(0,i,mat,dp,n));
        }
        return ans;
    }
};