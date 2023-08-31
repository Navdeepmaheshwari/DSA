class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
       vector<int> maxReach(n+1, 0);
        
        for(int i = 0; i<ranges.size(); i++) {
            
            int s=max(0,i-ranges[i]);
            int e=min(n,i+ranges[i]);
            
            maxReach[s]=max(maxReach[s],e);   
        } 
        
        // for(auto x:maxReach){
        //     cout<<x<<" ";
        // }
        
        int taps=0;
        int maxx=0;
        int curr=0;
        for(int i=0;i<=n;i++){
            
            if(i>maxx)return -1;
            
            if(i>curr){
               taps++;
               curr=maxx;
            }
            maxx=max(maxx,maxReach[i]);
        }
        return taps;
        
    }
};