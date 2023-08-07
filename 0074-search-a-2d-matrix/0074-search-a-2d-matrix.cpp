class Solution {
public:
// A m*n matrix converted into an array: matrix[x][y] : a[x * n + y]
// An array can be converted into n * m matrix: a[x] : matrix[x / n][x % n]
      //O(log(m*n)
     bool searchMatrix(vector<vector<int>>& mat, int target) {
         
        int m=mat.size(),n=mat[0].size();
         if(m==0||n==0)return false;
         
         int lo=0,hi=n*m-1;
         
         while(lo<=hi){
            int mid=lo+(hi-lo)/2;
           /*    
               agar normal ka mid hota to sidha a[mid] but matrix m 
               a[mid]= mat[mid/n][mid%n]
           */
            int curr=mat[mid/n][mid%n];
            if(curr==target)return true;
            else if(curr<target){
                     lo=mid+1;
            }
            else hi=mid-1;
         }
        return false;   
    }
    
     //O(m*n)
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