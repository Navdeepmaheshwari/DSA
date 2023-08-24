class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    vector<string>ans;
    void solve(int i,int j,vector<vector<char>>& board,string curr, unordered_set<string>&st,int m,int n){
        
        if(curr.size()>=10)return;
        if(i<0||j<0||i>=m||j>=n)return;
        if(board[i][j]=='.')return;
        
        char c=board[i][j];
        board[i][j]='.';
        curr.push_back(c);
         if(st.find(curr)!=st.end()){
            st.erase(curr);
            ans.push_back(curr);
        }
       
        
        for(int k=0;k<4;k++){
            solve(i+dx[k],j+dy[k],board,curr,st,m,n);
        }
        curr.pop_back();
        board[i][j]=c; 
    }
   
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        unordered_set<string>st(words.begin(),words.end());
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                string curr="";
                solve(i,j,board,curr,st,m,n);
            }
        }
        return ans;
        
    }
};