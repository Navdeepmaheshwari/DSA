class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int k=2;
         int n=events.size();
        sort(events.begin(),events.end());
        // vector<vector<int>>dp(n,vector<int>(k+1,-1));
        // return solve(0,events,k,n,dp);
        
        //Tabulation
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int j=1;j<=k;j++){
                
                int val=0;
                
                val=0+dp[ind+1][j];
            
                // int i;
                // for(i=ind+1;i<n;i++){
                //     if(events[i][0]>events[ind][1]){
                //         break;
                //     }
                // }
                
                int i=ind+1;//nextIndex
                int high=n;
                while(i<high){
                    int mid=i+(high-i)/2;
                    if (events[ind][1] >= events[mid][0]) {
                        i = mid + 1;
                    } else {
                        high = mid;
                    }
                }
                
                val=max(val,events[ind][2]+dp[i][j-1]);

                dp[ind][j]=val;
            }
        }
        return dp[0][k];

    }
};