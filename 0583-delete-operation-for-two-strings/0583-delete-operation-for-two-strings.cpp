class Solution {
public:
    int lcs(string s1, string s2,int n,int m){
	  vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	  for(int i=0;i<=n;i++){
            dp[i][0]=0;
       }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
	    
	    for(int ind1=1;ind1<=n;ind1++){
	        for(int ind2=1;ind2<=m;ind2++){
	            
	            if(s1[ind1-1]==s2[ind2-1]){
	                dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
	            }
	            else{
	                dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
	            }
	        }
	    }
	    return dp[n][m];
	}
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
	    int len=lcs(s1,s2,n,m);
	    
	    return (n+m-(2*len));
    }
};