class Solution {
public:
     int mod=1e9+7;
    int n=4;
    int m=3;
    int f;

    int x[8]={-2,-2,2,2,-1,1,-1,1};
    int y[8]={-1,1,-1,1,-2,-2,2,2};

    int solve(int i , int  j , int k , vector<vector<int>>&ph , vector<vector<vector<int>>>&dp)
    {
        if(i>=n || j>=m || i<0 || j<0 || ph[i][j]==-1)
        { 
            return 0;
        }

        if(k==f)
        {
            // cout<<"val "<<ph[i][j]<<endl;
            return 1;
        }

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        long long t=0;

        for(int p=0 ; p<8 ; p++)
        {
            t%=mod;
            t+=solve(i+x[p],j+y[p],k+1,ph,dp)%mod;
        }

        return dp[i][j][k]=t;
    }


    int knightDialer(int l) 
    {
        vector<vector<int>>ph(4,vector<int>(3,-1));
        f=l;

        int j=1;
        ph[3][1]=0;

        for(int i=0 ; i<4 ; i++)
        {
            for(int k=0 ; k<3 ; k++)
            {
                if(i<3)ph[i][k]=j;
                j++;
            }
        } 

        long long ans=0;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(l+1,-1)));

        for(int i=0 ; i<4 ; i++)
        {
            for(int j=0 ; j<3 ; j++)
            {
                if(ph[i][j]!=-1)
                {
                    ans%=mod;
                    // cout<<ph[i][j]<<endl;
                    ans+=solve(i,j,1,ph,dp)%mod; // starting mein i have to pass 1 as we have picked the number
                    // cout<<ans<<endl;
                }
            }
        }

        return ans%mod;
    }
};