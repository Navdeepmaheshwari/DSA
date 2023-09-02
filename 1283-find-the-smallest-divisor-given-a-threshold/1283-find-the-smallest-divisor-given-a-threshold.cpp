class Solution {
public:
    int smallestDivisor(vector<int>& nums, int th) {
        
        //range 1-max element 
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;
       while(low<=high){
           int  mid=low+(high-low)/2;
           int sum=0;
           for(auto x:nums){
               int curr=ceil((double)x/mid);
               // cout<<curr<<" ";
               sum+=curr;
           }
           // cout<<endl;
           if(sum<=th){
               ans=mid;
               high=mid-1;
           }
           
           else{
               low=mid+1;
           }
       }
        return ans;
    }
};