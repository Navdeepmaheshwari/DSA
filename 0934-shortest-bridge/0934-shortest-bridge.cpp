class Solution {
public:
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis,int n,  queue<pair<pair<int,int>,int>>&q){
        
       if(i<0||i>=n||j<0||j>=n||grid[i][j]==0||vis[i][j])return;
        
        vis[i][j]=true; //mark as visited
        grid[i][j]=0;//convert to 0
        q.push({{i,j},0}); //push int queue {i,j,dis}
        
        for(int k=0;k<4;k++){
            int ni=i+dx[k],nj=j+dy[k];
            if(ni<0||ni>=n||nj<0||nj>=n||grid[ni][nj]==0||vis[ni][nj])continue;
            dfs(ni,nj,grid,vis,n,q);
        }
        
        return;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n=grid.size();
        bool first=false;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1&&!vis[i][j]){
                    dfs(i,j,grid,vis,n,q);
                    first=true;
                    break;
                }
            }
            
             if(first) break;
        }
        
        
        // now using BFS find the shortest path
        while(!q.empty()){
            
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dis=q.front().second;
            q.pop();
                        
            for(int k=0;k<4;k++){
                
                int ni=i+dx[k],nj=j+dy[k];
                if(ni<0||ni>=n||nj<0||nj>=n||vis[ni][nj])continue;
                
                if(grid[ni][nj]==1)return dis;
                else 
                {
                    vis[ni][nj]=true;
                    q.push({{ni,nj},dis+1});
                }
            }
        }
        return -1;
    }
};