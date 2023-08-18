class Solution {
public:
   bool solve(int i,vector<int>&nums,int n,vector<bool>&vis){
       
       if(i<0||i>=n||vis[i])return false;
       if(nums[i]==0)return true;
       vis[i]=true;
       bool isPossible=false;
        
        
        isPossible=isPossible||solve(i+nums[i],nums,n,vis)|| solve(i-nums[i],nums,n,vis);
        
        return isPossible;
    }
    bool canReach(vector<int>& nums, int start) {
        int n=nums.size();
        vector<bool>vis(n,0);
        return solve(start,nums,n,vis);
    }
};