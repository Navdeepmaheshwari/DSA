class Solution {
public:
    bool valid(int row,int col,vector<vector<char>>& board,char c){
        
        for(int i=0;i<9;i++){
            //check the entire coloum
            if(board[row][i]==c){
                return false;
            }
            //check entire row
            if(board[i][col]==c){
                return false;
            }
            
            //checking 3x3 grid
            int ro=3*(row/3) + i/3;
            int co=3*(col/3) + i%3;
            
            if(board[ro][co]==c){
                return false;
            }
            
           }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n=board.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(board[i][j]=='.'){
                    
                    for(char c='1';c<='9';c++){
                        
                        if(valid(i,j,board,c)){
                            board[i][j]=c;
                            
                            if(solve(board))return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
    }
};