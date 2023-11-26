class Solution {
public:
       int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int i = 1; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(matrix[i-1][j] && matrix[i][j]) matrix[i][j] = matrix[i-1][j]+1;
            }
        }
                
        int maxval = INT_MIN;
        for(vector<int> v : matrix)
            maxval = max(maxval, largestRectangleArea(v));
    
        return maxval;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        sort(heights.begin(), heights.end(), greater<int>());
        
        int res = INT_MIN;
        int minval = INT_MAX;
        
        for(int i = 0; i < heights.size(); i++)
        {
            minval = min(minval, heights[i]);
            res = max(res, minval*(i+1));   
        }
        
        return res;
};
};