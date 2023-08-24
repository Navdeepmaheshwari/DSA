class Solution {
public:
     int path(int row,int col,vector<vector<int>>& grid,int m,int n,int cnt,int zero,int ans)
    {
        if(row<0||col<0||row>=m||col>=n)return 0;
        if(grid[row][col]==-1||grid[row][col]==3)return 0;
        
        if(grid[row][col]==2){
            if(cnt==zero)return 1;
            return 0;
        }
         
        grid[row][col]=3;//mark as 3 (for visited)
      
        // cout<<cnt<<" ";
        int up=path(row-1,col,grid,m,n,cnt+1,zero,ans);
        int left=path(row,col-1,grid,m,n,cnt+1,zero,ans);
        int right= path(row,col+1,grid,m,n,cnt+1,zero,ans);
        int bottom= path(row+1,col,grid,m,n,cnt+1,zero,ans);
        
        grid[row][col]=0; //unmark
       
         
        return up+left+bottom+right;    
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0,zero=1;
        
        // zero=1 beacause start wale ko bhi -1 m krega in recusrsion so ek bdega
        int si,sj;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j]==1) si=i, sj=j;
                else if (grid[i][j]==0) zero++;
            }
        }
        // cout<<zero<<endl;
        return  path(si,sj,grid,m,n,0,zero,ans);
    }
};