class Solution {
public:
        long long solve(int ind,vector<vector<int>>& rides,int len, vector<long long>&dp){
        
        if(ind>=len)return 0;
        if(dp[ind]!=-1)return dp[ind];
            
        long long val=0;
        //not take
        val=0+solve(ind+1,rides,len,dp);
        
        //take
        //O(n)
        // int i;
        // for(i=ind+1;i<len;i++){
        //     if(rides[i][0]>=rides[ind][1]){
        //         break;
        //     }
        // }
            
         //O(logn)    
         int i=ind+1;//nextIndex
         int high=len;
         while(i<high)
         {
           int mid=i+(high-i)/2;
            if (rides[ind][1] > rides[mid][0]) {
                i = mid + 1;
            } 
            else {
                high = mid;
            }
        } 
            

        val=max(val,rides[ind][1]-rides[ind][0]+rides[ind][2]+solve(i,rides,len,dp));
        
        return dp[ind]=val;
        
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int len=rides.size();
        sort(rides.begin(),rides.end());
        vector<long long>dp(len,-1);
        return solve(0,rides,len,dp);
    }
};