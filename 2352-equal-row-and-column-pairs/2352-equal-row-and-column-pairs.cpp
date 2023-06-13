class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<int>>transpose;
        
        for(int j=0;j<col;j++){
            vector<int>temp;

                    for(int i=0;i<row;i++){

                        temp.push_back(grid[i][j]);
                    }
             transpose.push_back(temp);
        }
        
        int countpairs=0;
        for(int i=0;i<row;i++){
            
            for(int j=0;j<row;j++){
                
                if(grid[i]==transpose[j]){
                    countpairs++;
                }
            }
        }
        return countpairs;
    }
};