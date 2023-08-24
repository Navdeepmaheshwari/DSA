//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool solve(int i,int j,int m,int n,vector<vector<char>>& board, string &word,int w){
        if(w==word.size())return true;
        if(i<0||j<0||i==m||j==n)return false;
        if(board[i][j]!=word[w])return false;
        char c=board[i][j];
        board[i][j]='.';
        bool ans=false;
        for(int k=0;k<4;k++){
            ans=ans|solve(i+dx[k],j+dy[k],m,n,board,word,w+1);
        }
        board[i][j]=c;
        return ans;
        
    }
    bool wordSearch(vector<vector<char>>& board, string word) {
        //code here
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(board[i][j]==word[0]){
                   if(solve(i,j,m,n,board,word,0)) return true;
                }
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
        int n,m;
        cin>>n>>m;
        vector<vector<char>> mat(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
        string str; cin>>str;
        Solution ob;
        auto ans=ob.wordSearch(mat,str);
        cout<<ans<<"\n";
    }
    return 0;
}

// } Driver Code Ends