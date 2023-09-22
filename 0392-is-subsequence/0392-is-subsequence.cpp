class Solution {
public:
    bool isSubsequence(string s, string t) {
        map<char,vector<int>>mp;
        int n=t.size();
        for(int i=0;i<n;i++){
            
            mp[t[i]].push_back(i);
        }
        int min=-1,j;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()) 
                 return false;
            for( j=0;j<mp[s[i]].size();j++){
                if(mp[s[i]][j]>min)
                {
                    min=mp[s[i]][j]; 
                    break;
                }
                else
                {
                    mp[s[i]][j]=-1;
                }
            }
            
        
        if(j==mp[s[i]].size())
            return false;
         
        } 
        return true;
    }
};