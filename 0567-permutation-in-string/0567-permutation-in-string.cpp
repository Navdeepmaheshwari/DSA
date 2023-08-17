class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        int n=s2.size();
        for(auto x:s1){
            mp[x]++;
        }
        
        int j=0,i=0;
        int cnt=mp.size();;
        while(j<n){
            
            if(mp.find(s2[j])!=mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]]==0)cnt--;
            }
            
            if(j-i+1<s1.size()){
                j++;
            }
            else if(j-i+1==s1.size()){
                if(cnt==0)return true;
                
                if(mp.find(s2[i])!=mp.end()){
                    mp[s2[i]]++;
                    if(mp[s2[i]]==1)cnt++;
                }
                i++;
                j++;
            }
            
        }
        return false;
    }
};