class Solution {
public:
    double dp[101][101];
     double solve(int poured, int row, int glass)
    {
       
        if(row < 0 || glass > row || glass < 0)
        {
            return 0.00;
        }
        
      
        if(row == 0 && glass == 0)
        {
            return poured;
        }
        
         if(dp[row][glass] > -1)
        {
            return dp[row][glass];
        }
        // how much comes from left part- first coordinate(i -1, j - 1) then keep 1 for themself and then divide by 2
        double left = (solve(poured, row - 1, glass - 1) - 1) / 2;
        
        // if comes negative then, in reality zero comes
        if(left < 0)
        {
            left = 0;
        }
        
        // how much comes from right part- first coordinate(i - 1, j) then keep 1 for themself and then divide by 2
        double right = (solve(poured, row - 1, glass) - 1) / 2;
        
         // if comes negative then, in reality zero comes
        if(right < 0)
        {
            right = 0;
        }
        
  
        double total = left + right;
        
        return dp[row][glass]=total; 
        
        
    }
    double champagneTower(int poured, int query_row, int query_glass) {
         memset(dp, -1, sizeof(dp));
        return min(1.00, solve(poured, query_row, query_glass));
    }
};