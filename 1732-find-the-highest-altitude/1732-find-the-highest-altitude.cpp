class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int ans=0;
        for(int i=1;i<n;i++){
            gain[i]=gain[i]+gain[i-1];
        }
        
        return ans=max(ans,*max_element(gain.begin(),gain.end()));
    }
};