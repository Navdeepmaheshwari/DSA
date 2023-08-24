//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool isFound(int row,int cols,int target,vector<vector<int>>& mat){
        int lo=0,hi=cols-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(mat[row][mid]==target)return true;
            else if(mat[row][mid]<target){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return false;
    }
    bool search(vector<vector<int> > mat, int m, int n, int x) 
    {
         for(int i=0;i<m;i++){
             
             if(isFound(i,n,x,mat)){
                 return true;
             }
         }
        
        return false;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends