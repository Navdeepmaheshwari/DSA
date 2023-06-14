class Solution {
public:
   int solve(int idx,int target,vector<int>& nums){
        if(idx==nums.size()){
            if(target==0){
               return 1;
            }
            return 0;
        }
       
       int pos=solve(idx+1,target-nums[idx],nums);
       int neg= solve(idx+1,target+nums[idx],nums);
       return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,target,nums);
        
    }
};