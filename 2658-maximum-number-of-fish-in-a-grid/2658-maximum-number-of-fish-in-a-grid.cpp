class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    int  dfs(int row,int col,vector<vector<int>>& grid,int m,int n){
        
        if(row<0||row>=m||col<0||col>=n||grid[row][col]==0)return 0;
        
        int ans=grid[row][col];
        grid[row][col]=0;
        for(int i=0;i<4;i++){
            int nr=row+dx[i];
            int nc=col+dy[i];
            ans+=dfs(nr,nc,grid,m,n);
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,dfs(i,j,grid,m,n));
                }
            }
        }
        
        return ans;
    }
};