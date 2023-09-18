class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        
        int m=mat.size();
        int n=mat[0].size();
        
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
             
                // int cnt=0;
                if(mat[i][j]==1)cnt++;
            }
            pq.push({cnt,i});
        }
        while(k--){
            auto temp=pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};