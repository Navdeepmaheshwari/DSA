class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        int n=str.size();
        for(int i=0;i<n;i++){
            
            string s=str[i];
            sort(s.begin(),s.end());
            mp[s].push_back(str[i]);
        }
        for(auto&x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};