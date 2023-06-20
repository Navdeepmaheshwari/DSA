class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,-1);
        int len=2*k+1;
        if (len>n)return ans;
       
        vector<long long>presum(n);
        presum[0] = nums[0];
        for (int i = 1; i < n; i++)
          {  
            presum[i] = presum[i - 1] + nums[i];
          }
         
        presum.insert(presum.begin(),0); //add 0 in starting to solve when we subtract 
        // for(auto x:presum){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        for (int i = k; i + k < n; ++i){
            ans[i] = (presum[i+k+1]-presum[i-k]) /len;
        }
        return ans;
    }
};