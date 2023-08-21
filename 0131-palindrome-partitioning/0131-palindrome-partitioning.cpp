class Solution {
public:
    bool isPal(string &s, int lo, int hi)
    { 
        while(lo<=hi){
            if(s[lo]!=s[hi])
                return false;
            lo++;
            hi--;
        }
        return true;      
    }
    void solve(int ind,string &s,vector<string>&str,vector<vector<string>>&ans)
    {
        if(ind==s.size()){
            ans.push_back(str);
        }
        
        for(int i=ind;i<s.size();i++){
            
            if(isPal(s,ind,i)){
                str.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,str,ans);
                str.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>str;
        solve(0,s,str,ans);
        return ans;
    }
};