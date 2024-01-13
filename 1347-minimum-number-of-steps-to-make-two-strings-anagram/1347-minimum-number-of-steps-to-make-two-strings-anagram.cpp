class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp;
        
        for(char x:t){
            mp[x]++;
        }
        int ans=0;
        for(char i:s){
            
           if(mp.find(i)!=mp.end()){
               mp[i]--;
           }
        }
        
        for(auto x:mp){
            
            if(x.second>0){
                ans+=x.second;
            }
            
        }
        return ans;
    }
};