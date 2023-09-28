class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        int n = strs.size();
        sort(strs.begin(),strs.end());
        int sz = min(strs[0].size(),strs[n-1].size());
        for(int i=0;i<sz;++i){
            if(strs[0][i] == strs[n-1][i]) s.push_back(strs[0][i]);
            else break;
        }
        return s;
        
    }
};