class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
         int m=grid.size(),n=grid[0].size();
        vector<vector<int>>diff(m,vector<int>(n,0));
        vector<int>rowcnt(m),colcnt(n);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    rowcnt[i]++;
                    colcnt[j]++;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j]=rowcnt[i]+colcnt[j]-(m-rowcnt[i])-(n-colcnt[j]);
            }
        }
        return diff;
    }
};