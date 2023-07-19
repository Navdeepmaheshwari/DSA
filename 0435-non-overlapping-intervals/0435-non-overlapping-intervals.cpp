class Solution {
public:
    bool static comp(vector<int>&a,vector<int>&b){
        if(a[1]==b[1])return a[0]<b[0];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end(),comp);//sort on the basis of end points
        int cnt=0;
        int n=inter.size();
        vector<int>prev=inter[0];
        for(int i=1;i<n;i++){
         
            if(prev[1]>inter[i][0])cnt++;
            else prev=inter[i];
        }
        return cnt;
    }
};