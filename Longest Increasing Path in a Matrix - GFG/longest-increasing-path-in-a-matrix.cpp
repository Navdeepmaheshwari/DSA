//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {

        // Code here
         m=matrix.size();
         n=matrix[0].size();
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends