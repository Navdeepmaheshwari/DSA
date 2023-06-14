class Solution {
public:
	int f(int ind,vector<int>& arr,int sum,vector<vector<int>>&dp ){

	 if(ind==0){

	   if(sum==0&&arr[0]==0)return 2;
	   if(sum==0||sum==arr[ind])return 1;
	   return 0;
	 }
	    
	    if(dp[ind][sum]!=-1)return dp[ind][sum];
	    int notTake=f(ind-1,arr,sum,dp);
	    int take=0;
	    if(sum>=arr[ind]){
	        take=f(ind-1,arr,sum-arr[ind],dp);
	    }
	    
	    return dp[ind][sum]=(take+notTake);
	}
	
  	int perfectSum(vector<int>& arr, int sum)
	{int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,arr,sum,dp);
	}
	
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int total=0;
        for(auto x:arr){
            total+=x;
        }
        
        
        if(total-d<0||(total-d)%2)return 0;
      
        return perfectSum(arr,(total-d)/2);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
        
    }
};