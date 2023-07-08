class Solution {
public:
    int longestCommon (string s1, string s2, int n)
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                
                if(s1[ind1-1]==s2[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                    
                }
                else{
                    dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s1) {
        int n=s1.size();
        string s2=s1;
        reverse(s1.begin(),s1.end());
        // cout<<s2<<"  "<<s1<<endl;
        return longestCommon(s2,s1,n) ;
    }
};