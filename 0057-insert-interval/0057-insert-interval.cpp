class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        for(auto vec:intervals){
           if(vec[1]<newInterval[0])ans.push_back(vec);
            else if(vec[0]>newInterval[1]){
                ans.push_back(newInterval);
                newInterval=vec;
            }
            else{
                newInterval[0]=min(newInterval[0],vec[0]);
                newInterval[1]=max(newInterval[1],vec[1]);
            }  
        } ans.push_back(newInterval); return ans;
    }
};