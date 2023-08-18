class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        vector<int>cnt(n,0);
        map<pair<int,int>,int>mp;
        for(auto x:roads){
            cnt[x[0]]++;
            cnt[x[1]]++; 
            
            mp[{x[0],x[1]}]++;
        }
      
        // for(auto x:cnt){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        int maxx=INT_MIN;
        for(int i=0;i<n;i++){
         
            for(int j=i+1;j<n;j++){
                int count= cnt[i]+cnt[j];
                count-=mp[{i,j}]+mp[{j,i}];//remove cnt of duplicates
                
                maxx=max(count,maxx);
                
            }
            
        }
        return maxx;
    }
};