//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> h)
    {
        //code here
        int m=h.size(),n=h[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cntUninfected=0;
        queue<vector<int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(h[i][j]==2){
                    q.push({i,j,0});//row,col,time
                    vis[i][j]=1;
                }
                else if(h[i][j]==1)cntUninfected++;
            }
        }
        
        int dro[]={-1,0,1,0};
        int dco[]={0,-1,0,1};
        int timee=0,cnt=0;
        while(!q.empty()){
           auto x=q.front();q.pop();
           int r=x[0],c=x[1],t=x[2];
           timee=max(timee,t);
           
           for(int i=0;i<4;i++){
               int nro=r+dro[i],nco=c+dco[i];
               
               if(nro>=0&&nro<m&&nco>=0&&nco<n&&!vis[nro][nco]&&h[nro][nco]==1){
                   q.push({nro,nco,t+1});
                   vis[nro][nco]=1;
                   cnt++;
               }
           }
        }
        
        if(cntUninfected!=cnt)return -1;
        return timee;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends