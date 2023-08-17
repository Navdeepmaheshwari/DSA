class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
      int m=mat.size(),n=mat[0].size();
        unordered_map<int,pair<int,int>>mp;
        unordered_map<int,int>rowcnt,colcnt; //store the cnt of particular row and col
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        
        
        for(int i=0;i<arr.size();i++){
            
            int row=mp[arr[i]].first;
            int col=mp[arr[i]].second;
            
            
            rowcnt[row]++;
            colcnt[col]++;
            
            //agar ek row me col ke equal element aa gye mtlb fully paint hogyi row
            //simlarly agar ek col me row ke barbar element aa gye mtlb fully paint hogyi col
            if(rowcnt[row]==n||colcnt[col]==m)return i; 
        }
        
        return -1;
    }
};