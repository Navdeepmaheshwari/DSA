class Solution {
public:
    void solve(int cntO,int cntC,string&res, vector<string>&ans,int n){
       
        if(cntO==0&&cntC==0){
            ans.push_back(res);
            return ;
        }
        
      
        if(cntO!=0){
            res.push_back('(');
            solve(cntO-1,cntC,res,ans,n);
            res.pop_back();
        }
        
        
         if(cntO<cntC){
            res.push_back(')');
            solve(cntO,cntC-1,res,ans,n);
            res.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        int cntO=n,cntC=n;
        
        vector<string>ans;
        string res="";
        solve(cntO,cntC,res,ans,n);
        return ans;
    }
};