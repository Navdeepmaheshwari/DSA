class Solution {
public:
        void solve(int i,vector<int>& nums, vector<vector<int>>&ans,vector<int>&res,int n){
        
        if(i==n){
            if(find(ans.begin(), ans.end(), res) == ans.end()){
                 ans.push_back(res);
            }
            
            return;
        }
        
            res.push_back(nums[i]);
            solve(i+1,nums,ans,res,n);
            res.pop_back();
            solve(i+1,nums,ans,res,n);
      
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>res;
        
        solve(0,nums,ans,res,n);
        return ans;
    }
};