class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) { 
        vector<int>adj[n];
        vector<int>indegree(n,0);
        queue<int>q;
        vector<int>topo;
        
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        
        // for(int i=0;i<n;i++){
        //     for(auto node:adj[i]){
        //         indegree[node]++;
        //     }
        // }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
           int node=q.front();q.pop(); 
            topo.push_back(node);
            
            for(auto x:adj[node]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }
        
        return topo.size()==n;
    }
};