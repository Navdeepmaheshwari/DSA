class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0; 
        
        //increasing 
        int curr=nums[0];
        int len=1;
        for(int i=1;i<n;i++){
            
            if(nums[i]>curr){
                curr=nums[i];
                len++;
            }
            else{
                curr=nums[i];
                ans=max(ans,len);
                len=1;
            }
        }
        
        ans=max(ans,len);
        
        //decreasing
        len=1;
        curr=nums[0];
        
        for(int i=1;i<n;i++){
            
            if(nums[i]<curr){
                curr=nums[i];
                len++;
            }
            else{
                curr=nums[i];
                ans=max(ans,len);
                len=1;
            }
        }
        ans=max(ans,len);
        return ans;
    }
};