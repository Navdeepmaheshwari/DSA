class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    int f(int row,int col,vector<vector<int>>& matrix,int prev,int m,int n,vector<vector<int>>&dp){
       int maxx=1;
        if(row<0||row>=m||col<0||col>=n||matrix[row][col]<=prev){
            return 0;
        }
        if(dp[row][col]!=-1 )return dp[row][col];
        for(int i=0;i<4;i++){
            int nrow=row+dx[i],ncol=col+dy[i];
            maxx=max(maxx,1+f(nrow,ncol,matrix,matrix[row][col],m,n,dp));
        }
        return dp[row][col]= maxx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n+1,-1));
        int ans=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,f(i,j,matrix,-1,m,n,dp));
            }
        }
        return ans;
    }
};