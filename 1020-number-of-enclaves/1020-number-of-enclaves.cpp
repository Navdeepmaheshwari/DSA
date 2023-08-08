class Solution {
public:
    int dro[4]={-1,0,1,0};
    int dco[4]={0,-1,0,1};
    void dfs(int row,int col,vector<vector<int>>& grid,int m,int n){
        
        if(row<0||row>=m||col>=n||col<0||grid[row][col]!=1){
            return;
        }
        grid[row][col]=0;
        
        for(int i=0;i<4;i++){
            int nrow=row+dro[i];
            int ncol=col+dco[i];
            
            dfs(nrow,ncol,grid,m,n);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<n-1;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid,m,n);
            }
            if(grid[m-1][i]==1){
                dfs(m-1,i,grid,m,n);
            }
        }
        
        for(int i=0;i<m-1;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,m,n);
            }
            if(grid[i][n-1]==1){
                dfs(i,n-1,grid,m,n);
            }
        }
        
      int cnt = 0;
        for(int i = 1; i < m-1; i++)
        {
            for(int j = 1; j < n-1; j++)
            {
                if(grid[i][j] == 1)
                cnt++;
            }
        }

        return cnt;
    }
};