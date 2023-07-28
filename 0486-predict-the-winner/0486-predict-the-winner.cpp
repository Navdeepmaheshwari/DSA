class Solution {
public:
    int solve(int i,int j,vector<int>&nums){
       if(i>j)return 0;
        if(i==j)return nums[i];
        
        //two case ya to left wala le ya right
        int left=nums[i]+min(solve(i+1,j-1,nums),solve(i+2,j,nums));
        int right=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        
        return max(left,right);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
          int n=nums.size();  
          int total=0;
           for(auto x:nums){
                total+=x;
            }
         int first=solve(0,n-1,nums);
        cout<<first<<" "<<total<<endl;
        //agar first ka total-first se jyda ya barabar then true(winner)
        
        int second=total-first;
      return first>=second;
    }
};