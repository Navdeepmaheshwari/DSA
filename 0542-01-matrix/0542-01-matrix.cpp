class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>res(m,vector<int>(n,0));
         vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;//{row,col,dis}
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        while(!q.empty()){
            
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dis=q.front().second;
            q.pop();
             res[i][j]=dis;
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                
                if(ni<0||ni>=m||nj<0||nj>=n||vis[ni][nj])continue;
                
                q.push({{ni,nj},dis+1});
                vis[ni][nj]=1;
            }
        }
        
        
        return res;
    }
};