class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i=0,j=1;
        int maxi=INT_MIN;
        int n=nums.size();
        if(n==1)return n;
        int cnt=1;
        while(j<n){
            
            if(nums[j-1]<nums[j]){
                cnt++;
            }
            else{
                cnt=1;
            }
            j++;
            maxi=max(cnt,maxi);
        }
        return maxi;
    }
    
};