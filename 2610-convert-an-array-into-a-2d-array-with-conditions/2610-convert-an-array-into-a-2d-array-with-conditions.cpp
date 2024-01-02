class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;        
        }
        vector<vector<int>>ans;
        int n=mp.size();
        // cout<<n;
        
        while(mp.size()){
            vector<int>res;
            for(auto x:mp){
                // cout<<x.first<<" "<<x.second<<endl;
                res.push_back(x.first);
            }
            for(auto i:res){
                
                if(mp[i]==1)mp.erase(i);
                else{
                    mp[i]--;
                }
            }
            
            ans.push_back(res);
        }
        
        return ans;
    }
};