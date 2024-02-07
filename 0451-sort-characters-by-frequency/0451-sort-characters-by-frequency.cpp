class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans="";
        for(auto x:s){
            mp[x]++;
        }
        
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        
        while(!pq.empty()){
            
            auto x=pq.top();pq.pop();
            int cnt=x.first;
            char c=x.second;
            while(cnt--){
                ans+=c;
            }
        }
        return ans;
    }
};