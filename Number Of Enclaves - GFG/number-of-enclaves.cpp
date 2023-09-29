//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i==0||j==0||j==m-1||i==n-1){
                    if(grid[i][j]==1){
                        vis[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
                
        }
        
        int delro[]={-1,0,1,0};
        int delco[]={0,-1,0,1};
        while(!q.empty()){
            int ro=q.front().first;
            int co=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nro=ro+delro[i];
                int nco=co+delco[i];
                
                if(nro>=0&&nco>=0&&nro<n&&nco<m&&!vis[nro][nco]&&grid[nro][nco]==1){
                    q.push({nro,nco});
                    vis[nro][nco]=1;
                }
            }
        }
        int cnt=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(vis[i][j]==0&&grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends