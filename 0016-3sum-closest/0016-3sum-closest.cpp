class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2]; //inital 
        for(int i=0;i<n-2;i++){
            
            int lo=i+1,hi=n-1;
            
            while(lo<hi){
                
                int curr=nums[i]+nums[lo]+nums[hi];
                
                if(abs(ans-target) > abs(curr-target))ans=curr;
                
                if(curr==target)break;
                
                if(curr>target){
                    hi--;
                }else{
                    lo++;
                }
            }
           
        }
        return ans;
    }
};