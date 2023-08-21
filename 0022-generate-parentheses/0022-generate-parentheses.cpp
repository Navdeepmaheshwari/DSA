class Solution {
public:
    void solve(int cntO,int cntC,string&res, vector<string>&ans,int n){
        
        if(cntO==0&&cntC==0){
            ans.push_back(res);
            return ;
        }
        
        //cntO==cntC then we take first open bracket
        if(cntO==cntC){
            res.push_back('(');
            solve(cntO-1,cntC,res,ans,n);
            res.pop_back();
        }
        
        //cntO==0 then we only have 1 option take close bracket
        else if(cntO==0){
            res.push_back(')');
            solve(cntO,cntC-1,res,ans,n);
            res.pop_back();
        }

        // else we have 2 options either open or close
        else{
            res.push_back('(');
            solve(cntO-1,cntC,res,ans,n);
            res.pop_back();
            
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