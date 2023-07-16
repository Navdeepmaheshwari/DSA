class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>>ans;
        if(grid[start[0]][start[1]]==0)return ans;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>>pq;//dis,price,row,col
        queue<vector<int>>q;//row,col,dis
        
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));//visited array
        
        q.push({start[0],start[1],0});
        // chk start point valid?
        if(grid[start[0]][start[1]] >= pricing[0] && grid[start[0]][start[1]] <= pricing[1]){
            pq.push({0, grid[start[0]][start[1]], start[0], start[1]});
        }
        
        vis[start[0]][start[1]]=1;
        
        while(!q.empty()){
            auto x=q.front();q.pop();
            int row=x[0],col=x[1],dis=x[2];
            
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]!=0){
                     if(grid[nrow][ncol] >= pricing[0] && grid[nrow][ncol] <= pricing[1])
                     {
                        pq.push({dis+1,grid[nrow][ncol] ,nrow, ncol});
                     }
                    q.push({nrow,ncol,dis+1});
                    vis[nrow][ncol]=1;

                }
            }
        }
        
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            ans.push_back({cur[2], cur[3]});
            k--;
            if(k == 0)
                break;
        }
        return ans;
    }
    
};