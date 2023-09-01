class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    void dfs(int row,int col,vector<vector<char>>& grid,int m,int n){
        
        if(row<0||row>=m||col<0||col>=n||grid[row][col]=='0')return;
        grid[row][col]='0';
        
        for(int i=0;i<4;i++){
            
            int nr=row+dx[i];
            int nc=col+dy[i];
            dfs(nr,nc,grid,m,n);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid,m,n);
                }
            }
        }
        return cnt;
        
    }
};

