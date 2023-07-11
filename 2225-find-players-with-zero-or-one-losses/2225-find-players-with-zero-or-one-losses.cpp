class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans(2);
        map<int,pair<int,int>>mp;// player,cntW.cntL
        
        for(auto x:matches){
            mp[x[0]].first++;
            mp[x[1]].second++;
        }
        
        // for(auto x:mp){
        //     cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
        // }
        
        for(auto x:mp){
            if(x.second.second==0){
                ans[0].push_back(x.first);
            }
             else if(x.second.second==1){
                ans[1].push_back(x.first);
            }
            // cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
        }
        return ans;
    }
};