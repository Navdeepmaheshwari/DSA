class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<pair<int,int>>adj[n];
        for(auto x:flights){
            int u=x[0];
            int v=x[1];
            int dis=x[2];
            adj[u].push_back({v,dis});
        }
        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>q; //{stops,node,dis}
        q.push({0,{src,0}});
        dist[src]=0;
        
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int stops=x.first;
            int node=x.second.first;
            int dis=x.second.second;
            
            if(stops>k)continue;
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                
                if(dist[adjNode]>dis+wt &&stops<=k){
                    dist[adjNode]=dis+wt;
                    q.push({stops+1,{adjNode,dis+wt}});
                }
            }
        }
        
        
        if(dist[dst]==1e9)return -1;
        return dist[dst];
        
    }
};