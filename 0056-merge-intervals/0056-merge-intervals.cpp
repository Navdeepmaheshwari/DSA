class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        vector<vector<int>>ans;
        int n=inter.size();

        sort(inter.begin(),inter.end());
        vector<int>res=inter[0];
        // for(auto x:inter){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        for(auto v:inter){ 
            if(v[0]<=res[1]){
                res[0]=res[0];
                res[1]=max(res[1],v[1]);
            }
            else{
                ans.push_back(res);
                res=v; //set curr vector to result
            }
        }
        ans.push_back(res);
        return ans;
    }
};