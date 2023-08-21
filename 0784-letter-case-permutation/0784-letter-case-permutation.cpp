class Solution {
public:
    void solve(int i,string s,vector<string>&ans,int n){
        
        if(i==n){
            ans.push_back(s);
            return;
        }
        
          if(isalpha(s[i])){
              
                s[i]=toupper(s[i]);
                solve(i+1,s,ans,n);
              
                s[i]=tolower(s[i]);
                solve(i+1,s,ans,n);
            }
            else{
                solve(i+1,s,ans,n);
            }
    }
    vector<string> letterCasePermutation(string s) {
        
        vector<string>ans;
        
        int n=s.size();
        
        solve(0,s,ans,n);
        
        return ans;
    }
};