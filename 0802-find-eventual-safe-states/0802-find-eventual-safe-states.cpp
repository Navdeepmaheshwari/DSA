class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int>outdegree(N);
        vector<vector<int>>Revgraph(N);
        queue<int>q;
        for(int i=0;i<N;i++){
            for(auto v:graph[i]){
                Revgraph[v].push_back(i); //storing in reverse;
            }
            
            int size=graph[i].size();
            outdegree[i]=size;
            
            if(outdegree[i]==0)q.push(i); //if outdegree ==0 push it in queue beacuse it is safe
        }
        
        vector<int>safe(N);
        vector<int>ans;
        while(!q.empty()){
          int node=q.front();q.pop();
            safe[node]=1; //mark node as safe
            
            for(auto x:Revgraph[node]){
                outdegree[x]--;
                if(outdegree[x]==0)q.push(x);
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (safe[i]) ans.push_back(i);
        }
        
        return ans;
    }
};