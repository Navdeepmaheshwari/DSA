class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans;
        vector<int>pascal;
        vector<int>res;
        for(int i=0;i<=rowIndex;i++){
            pascal.push_back(1);
            for(int j=1;j<i;j++){
                pascal[j]=ans[i-1][j]+ans[i-1][j-1];
            }
            ans.push_back(pascal);
            
        }
        return pascal;
    }
};