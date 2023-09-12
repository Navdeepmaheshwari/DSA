class Solution {
public:
    int minDeletions(string s) {
        
        unordered_map<char,int>mp;
        unordered_set<int>st;
        for(auto x:s){ 
            mp[x]++;
        }
        // a-3,b-3,c=2;
        priority_queue<int>pq;//store freq.
        for(auto x:mp){
            pq.push(x.second);
        }
        
        int del=0;
        while(!pq.empty()){
            // cout<<pq.top()<<" ";
            int curr=pq.top();pq.pop();
            
            while(curr>0&&st.find(curr)!=st.end()){
                curr--;
                del++;
            }
            
            st.insert(curr);
        }
        return del;
    }
};