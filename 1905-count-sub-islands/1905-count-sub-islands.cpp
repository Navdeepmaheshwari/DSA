class Solution {
public:
     int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    void dfs(int row,int col,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>& vis,int m,int n,bool&flag){
        
        if(row<0||row>=m||col<0||col>=n||!grid2[row][col])return;
        if(grid2[row][col]==1&&grid1[row][col]==0)flag=false;
        
        grid2[row][col]=0;
        
        for(int i=0;i<4;i++){
            int nx=row+dx[i];
            int ny=col+dy[i];
            
            dfs(nx,ny,grid1,grid2,vis,m,n,flag);
        }
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid2.size(),n=grid2[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid2[i][j]==1&&vis[i][j]==0){
                    bool flag=true;
                    dfs(i,j,grid1,grid2,vis,m,n,flag);
                    if(flag)cnt++;
                }
            }
        }
        return cnt;
    }
};