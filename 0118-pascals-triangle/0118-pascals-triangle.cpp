class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>pascal;
        
        for(int i=0;i<numRows;i++){
            pascal.push_back(1);
            // cout<<i<<endl;
            for(int j=1;j<i;j++){
                pascal[j]=ans[i-1][j]+ans[i-1][j-1];
            }
            // for(auto x:pascal)
            //   cout<<x<<" ";
            // cout<<endl;
            ans.push_back(pascal);
        }
        return ans;
        
    }
};