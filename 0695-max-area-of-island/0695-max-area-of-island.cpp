class Solution {
public:
    int dro[4]={-1,0,1,0};
    int dco[4]={0,-1,0,1};
    
    void dfs(int r,int c,vector<vector<int>>& grid,int m,int n, vector<vector<int>>&vis,int&curr){
        
        if(r<0||r>=m||c<0||c>=n||grid[r][c]==0||vis[r][c]){
            return;
        }
        curr+=1;
        vis[r][c]=1;
        int cnt=0;
        for(int i=0;i<4;i++){
            int nro=r+dro[i],nco=c+dco[i];
            dfs(nro,nco,grid,m,n,vis,curr);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(!vis[i][j]&&grid[i][j]==1){
                    int curr=0;
                   dfs(i,j,grid,m,n,vis,curr);
                    ans=max(ans,curr);
                }
            }
        }
        if(ans==INT_MIN)return 0;
        return ans;
    }
};