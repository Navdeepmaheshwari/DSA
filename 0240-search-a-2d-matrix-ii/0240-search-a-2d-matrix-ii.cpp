class Solution {
public:
    
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
    
      bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size(),n=mat[0].size();
         
         for(int i=0;i<m;i++){
             
             if(isFound(i,n,target,mat)){
                 return true;
             }
         }
        
        return false;
    }
    
    
//     bool searchMatrix(vector<vector<int>>& mat, int target) {
//         int m=mat.size(),n=mat[0].size();
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(mat[i][j]==target)return true;
//             }
//         }
//         return false;
//     }
};