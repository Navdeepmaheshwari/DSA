class Solution {
public:
    void comb(int num,int n,int k,vector<vector<int>>&ans,vector<int>&ds){
        
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
       
        for(int i=num;i<=n;i++){
             
            ds.push_back(i);
            comb(i+1,n,k,ans,ds);
            ds.pop_back();
        }
           
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>ds;
        comb(1,n,k,ans,ds);
        return ans;
    }
};