class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size();
        
        string ans="";
        int ansi = -1, ansj = 0; //index of required string
        if(n>m)return ans;
        unordered_map<char,int>mpt;
        for(auto x:t){
            mpt[x]++;
        }
        
        int i=0,j=0;
        int cnt=mpt.size();
        int minn=INT_MAX;
        unordered_map<char,int>mps;
        while(j<m){
            
            if(mpt.find(s[j])!=mpt.end()){
                mps[s[j]]++;
                if(mps[s[j]]==mpt[s[j]])cnt--;
            }
            
            while(cnt==0){
                
                 if(j-i+1<minn){
                    minn=j-i+1;
                    ansi=i,ansj=j; //update index
                }
                
                if(mpt.find(s[i])!=mpt.end()){
                    mps[s[i]]--;
                     if (mps[s[i]] < mpt[s[i]]) {  //if freq decrese mean s[i]is required
                        cnt++;
                    }
                  
                }
                  i++;
            }
            
            j++;
        }
        
      return (ansi == -1) ? "" : s.substr(ansi, ansj - ansi + 1);
    }
};