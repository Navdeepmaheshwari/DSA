//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int mat[MAX][MAX],int m,int n,int k)
    {
 		// Your code goes here.
 		vector<int>ans;
        int dir=0;
        int top=0,bottom=m-1,left=0,right=n-1;
        while(top<=bottom && left<=right){
            if(dir==0){
                
                for(int i=left;i<=right;i++){
                    ans.push_back(mat[top][i]);
                }
                top+=1;
                dir=1;
            }
            else if(dir==1){
              
                for(int i=top;i<=bottom ;i++){
                    ans.push_back(mat[i][right]);
                }
                right-=1;
                dir=2;
            }
            else if(dir==2){
                
                for(int i=right;i>=left;i--){
                  ans.push_back(mat[bottom][i]);  
                }
                bottom-=1;
                dir=3;
            }
            else if(dir==3){
                
                for(int i=bottom;i>=top;i--){
                    ans.push_back(mat[i][left]);
                    
                }
                left+=1;
                dir=0;
            }
        }
        
        
       return ans[k-1];
 		
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends