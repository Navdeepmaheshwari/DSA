class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        int maxi=1;
        int last=0;
        sort(arr.begin(),arr.end());//sorting helps to convert problem into LIS
        vector<int>dp(n,1),hash(n,0);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                
                if(arr[i]%arr[j]==0&&1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
          
         //for last index
          if(dp[i]>maxi){
             maxi=dp[i];
             last=i;
          }
        }
        
        vector<int>lds;
        lds.push_back(arr[last]);
        while(hash[last]!=last){
            last=hash[last];
            lds.push_back(arr[last]);
        }
        
        reverse(lds.begin(),lds.end());
        return lds;
    }
};