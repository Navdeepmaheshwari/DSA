class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_set<int>s;
        for(auto x:arr){
            mp[x]++;
        }
        
        for(auto p:mp){
            s.insert(p.second);
        }
        
        if(mp.size()==s.size())return true;
        
        return false;
    }
};