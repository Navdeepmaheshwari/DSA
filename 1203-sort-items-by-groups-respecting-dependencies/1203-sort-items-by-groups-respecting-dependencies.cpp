class Solution {
public:
     vector<int> topo_sort( vector<vector<int>>& adj, vector<int>& deg, int sz){
        //Kahn's algorithm
        queue<int> q;
        for (int i=0; i<sz; i++)
            if (deg[i]==0) q.push(i);
        vector<int> res;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            res.push_back(x);
            for(int y: adj[x]){
                deg[y]--;
                if(deg[y]==0) q.push(y);
            }
        }
        for(int i=0; i<sz; i++)
            if(deg[i]>0) return {};
        return res;
    }
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        for(int i=0; i<n; i++){
            if (group[i]==-1) group[i]=m++;
        }
        
        vector<vector<int>> adjgrp(m) , adjit(n);
        vector<int>deggrp(m),degit(n);
        
        
        for(int i=0; i<n; i++){
            int to_i=group[i];
            for(int from: beforeItems[i]){
                int from_j=group[from];
                if(to_i!=from_j){
                    adjgrp[from_j].push_back(to_i);
                    deggrp[to_i]++;
                }
                adjit[from].push_back(i);
                degit[i]++;
            }
        }
        
        // int cnt=0;
        // for(auto x:degit){
        //     cout<<cnt++<<"->"<<x<<endl;
        //     // for(auto y:x){
        //     //     cout<<y<<" ";
        //     // }
        //     // cout<<endl;
        // }
        
        vector<int> sort_item=topo_sort(adjit, degit, n);
        vector<int> sort_group=topo_sort(adjgrp, deggrp, m); 

        vector<vector<int>> item_gp(m);
        for(int i: sort_item)
            item_gp[group[i]].push_back(i);
        
//         for(auto x:sort_item){
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
//         for(auto x:sort_group){
//             cout<<x<<" ";
//         }
        
//          cout<<endl;
        
//         for(auto x:item_gp){
//             for(auto y:x){
//                 cout<<y<<" ";
//             }
//             cout<<endl;
//         }

        
        vector<int> ans;
        for(int i : sort_group) {
            for(int item : item_gp[i]) {
                ans.push_back(item);
            }
        }
        
        return ans;

    }
};