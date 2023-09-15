class Solution {
public:
    int findPar(vector<int>&parent,int node){
        
        if(parent[node]==node)return node;
        return parent[node]=findPar(parent,parent[node]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& po) {
         int n = po.size();
        vector<pair<int, pair<int, int>>> edges;  
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dis = abs(po[i][0] - po[j][0]) + abs(po[i][1] - po[j][1]);
                edges.push_back({dis, {i, j}});
            }
        }
        
        sort(edges.begin(),edges.end());
        vector<int> parent(n);
        //Each point as its own parent
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        int minCost = 0; //minimum cost
        int numEdges = 0; //number of edges
        
        // Kruskal's algorithm
        for(auto edge:edges){
            int dis = edge.first; 
            int u = edge.second.first;
            int v = edge.second.second; 
            int ul_u = findPar(parent, u); 
            int ul_v = findPar(parent, v); 
            if (ul_u != ul_v) {
                parent[ul_u] = ul_v; 
                minCost += dis; // Add edge to MST
                numEdges++; // Increase edge count
            }
            
            // If we have added n-1 edges (spanning tree), break
            if (numEdges == n - 1) {
                break;
            }
        }
        
        return minCost;
        
    }
};