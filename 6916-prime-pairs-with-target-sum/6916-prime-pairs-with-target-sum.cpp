class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>ans;
        vector<bool>prime(n+1,true);
        prime[0]=prime[1]=false;
        
        for(int i=2;i<=n;i++){
            
            if(prime[i]==true){
                for(int j=2*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        
        for(int i=2;i<=n/2;i++){
            int j = n - i; 
            if(prime[i] && prime[j]){
                ans.push_back({i,j}); 
            }
        }
        return ans;
    }
};