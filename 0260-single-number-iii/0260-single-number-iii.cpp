class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto x:nums){
            mp[x]++;
        }
        for(auto i:mp){
            if(i.second==1)ans.push_back( i.first);
        }
        return ans;
    }
};