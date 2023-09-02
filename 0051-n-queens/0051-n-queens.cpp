class Solution {
public:
    bool isSafe(int row,int col,vector<string>&res,int n){
        int r=row,c=col;
     // check for upper diagonal
        while(r>=0&&c>=0){
            if(res[r][c]=='Q')return false;
            r--;
            c--;
        }
        
     // check for  row only move col from col->0
        r=row,c=col;
        while(c>=0){
            if(res[r][c]=='Q')return false;
            c--;
        }

     // check for lower diagonal
         r=row,c=col;
        while(r<n&&c>=0){
            if(res[r][c]=='Q')return false;
            r++;
            c--;
        }
        return true;
    }
    void solve(int col,vector<vector<string>>&ans, vector<string>&res,int n){
        
        //base case
        if(col==n){
            ans.push_back(res);
            return;
        }
        
       // check each row for col
        for(int row=0;row<n;row++){
            if(isSafe(row,col,res,n)){
              res[row][col]='Q';  
              solve(col+1,ans,res,n);  
              res[row][col]='.';  
            }  
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>res(n);
        string str(n,'.');
        
        // initalize res with all empty
        for(int i=0;i<n;i++){
            res[i]=str;
        }
        
        // now check for one by one all coloum
        solve(0,ans,res,n);
        
        return ans;
    }
};