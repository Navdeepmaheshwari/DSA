class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int cnt=0;
        int res=0;
       for(j=0;j<n;j++){
           
           if(nums[j]==0){
               cnt++;
           }
           
           while(cnt>1){
               if(nums[i]==0){
                   cnt--;
               }
               i++;
           }
           res=max(res,j-i);
       }
        return res;
    }
};