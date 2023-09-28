class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int>mp(256,-1);
        int n=s.size();
        int res=0;
        int l=0,r=0;
        
        while(r<n){
            
            if(mp[s[r]]!=-1) 
            {
                mp[s[l]]--;
                l=l+1;
                
                continue;
                
             }
            
            mp[s[r]]++;
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};