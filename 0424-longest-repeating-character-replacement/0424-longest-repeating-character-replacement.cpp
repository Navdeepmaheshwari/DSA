class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int cnt=0;
        int ans=-1;
        unordered_map<char,int> mp;
        while(j<n)
        {
            mp[s[j]]++;
            cnt=max(cnt,mp[s[j]]);
            
            int curr_len=j-i+1;
            if(curr_len-cnt>k)
            {
                mp[s[i]]--;
                i++;
            }
            curr_len=j-i+1;
            ans=max(ans,curr_len);
            j++;
        }
        
        return ans;
    }
};