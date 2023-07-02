class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            if(nums[i]>0)break;
            if(i>0 && nums[i]==nums[i-1])continue;
            int low=i+1,high=n-1;
            
            while(low<high){
                
                if(nums[i]+nums[low]+nums[high]==0){
                    
                    res.push_back({nums[i],nums[low],nums[high]});
                    
                    int a=nums[low], b=nums[high];
                    
                   while(low<high && nums[low]==a){
                       low++;
                   }
                    
                   while(low<high  && nums[high]==b){
                       high--;
                   }
 
                }
                
                 else if(nums[i]+nums[low]+nums[high]<0)  low++;
                 else if(nums[i]+nums[low]+nums[high]>0)  high--;
            }
            
        }
        return res;
    }
};