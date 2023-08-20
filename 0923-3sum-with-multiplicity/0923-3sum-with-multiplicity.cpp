class Solution {
public:
    int MOD=1e9+7;
    
     int threeSumMulti(vector<int>& nums, int target) {
        int n = nums.size(),  count = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++){
            count = (count + mp[target - nums[i]]) % MOD;
            
            for(int j=0; j<i; j++){
                mp[nums[i] + nums[j]]++;
            }
        }
        
        return count;
    }
    
//     int threeSumMulti(vector<int>& nums, int target) {
        
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         int ans=0;
//         for(int i=0;i<n;i++){        
//             int low=i+1,high=n-1;
//             while(low<high){
                
//                  if(nums[i]+nums[low]+nums[high]==target){
                    
//                     long long cntl=1,cnth=1;
                     
//                      while(low<high&&nums[low]==nums[low+1]){
//                          low++;
//                          cntl++;
//                      }
//                      while(low<high&&nums[high]==nums[high-1]){
//                          high--;
//                          cnth++;
//                      }
                     
//                      //if low==high mean element are same so nC2
//                      // 2 elements from n combinations,where n (cntl/cnth).
//                      if(low==high){
//                          long long curr=(cntl*(cntl-1))/2; //nC2
//                          ans=(ans+curr)%MOD;
//                      }
//                       //if low!=high simply multiply cntl*cnth;
//                      else{
//                          long long curr=cntl*cnth;
//                          ans=(ans+curr)%MOD;
//                      }
                     
//                    low++;
//                    high--;
//                 }
                
//                  else if(nums[i]+nums[low]+nums[high]<target)  low++;
//                  else if(nums[i]+nums[low]+nums[high]>target)  high--;
//             }
//         }
//         return ans;
//     }
};