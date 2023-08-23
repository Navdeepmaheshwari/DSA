class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gp) {
       unordered_map<int,vector<int>>mp;
        vector<vector<int>>ans;
        int n=gp.size();
        for(int i=0;i<n;i++){
            mp[gp[i]].push_back(i);
            
            if(mp[gp[i]].size()==gp[i]){
                ans.push_back(mp[gp[i]]);
                mp.erase(gp[i]);
            }
        }
        return ans;
    }
};