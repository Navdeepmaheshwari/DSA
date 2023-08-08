class Solution {
public:
    
void dfs(int ro,int co,vector<vector<char>> &mat, 
vector<vector<int>>&vis,int delro[],int delco[],int n,int m)
{
    vis[ro][co]=1;
    
    for(int i=0;i<4;i++){
        int nro=ro+delro[i];
        int nco=co+delco[i];
        
        if(nro>=0&&nro<n&&nco>=0&&nco<m&&!vis[nro][nco] && mat[nro][nco]=='O'){
            dfs(nro,nco,mat,vis,delro,delco,n,m);
        }
    }
    
}
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delro[]={-1,0,1,0};
        int delco[]={0,-1,0,1};
        for(int j=0;j<m;j++){
            
            if(!vis[0][j]&&mat[0][j]=='O'){
                dfs(0,j,mat,vis,delro,delco,n,m);
            }
            
             
            if(!vis[n-1][j]&&mat[n-1][j]=='O'){
                dfs(n-1,j,mat,vis,delro,delco,n,m);
            }
        }
        
        
        for(int i=0;i<n;i++){
            
            if(!vis[i][0]&&mat[i][0]=='O'){
                dfs(i,0,mat,vis,delro,delco,n,m);
            }
            
             if(!vis[i][m-1]&&mat[i][m-1]=='O'){
                dfs(i,m-1,mat,vis,delro,delco,n,m);
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(vis[i][j]==0&& mat[i][j]=='O'){
                    mat[i][j]='X';
                }
                
            }
        }
       
    }
};