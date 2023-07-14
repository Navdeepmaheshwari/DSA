class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp; //val,index;
        int n=nums.size();
        for(int i=0;i<n;i++){
              
            if(mp.find(target-nums[i])!=mp.end()){
                return {mp[target-nums[i]]+1,i+1}; //returning 1-Based
            }
            
            mp[nums[i]]=i;
        }
        return {};
    }
};