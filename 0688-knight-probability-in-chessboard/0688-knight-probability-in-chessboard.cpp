class Solution {
public:
    int dx[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };
    double solve(int r,int c,int k,int n,vector<vector<vector<double>>>&dp){
        // if(r < 0 || c < 0 ||r >= n || c >= n) return 0;
          if(dp[r][c][k] != -1) return dp[r][c][k];
        if(k==0)return 1;
      
        double ans=0;
        for(int i=0;i<8;i++){
            
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr >= 0 && nc >= 0 &&nr < n && nc < n) ans+=0.125*solve(nr,nc,k-1,n,dp);;
        }
        return dp[r][c][k]=ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return solve(row,column,k,n,dp);
    }
};