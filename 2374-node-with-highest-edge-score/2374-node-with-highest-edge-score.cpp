class Solution {
public:
    int edgeScore(vector<int>& edges) {
        priority_queue<pair<int,int>>pq;
        int n=edges.size();
        unordered_map<int,long long>mp;
        
        for(int i=0;i<n;i++){
            mp[edges[i]]+=i;
        }
        
       long long maxx = INT_MIN;
        int idx = 0;
		//Finding the maximum score and it's index
        for(int i = 0; i < n; i++){
            if(mp[i] > maxx){
                maxx = mp[i];
                idx = i;
            }
        }
        return idx;
        
    }
};