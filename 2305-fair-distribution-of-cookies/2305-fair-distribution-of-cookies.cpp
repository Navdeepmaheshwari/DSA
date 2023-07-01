class Solution {
public:
 int ans = INT_MAX;
    
    void search(vector<int>& cook,int ind,vector<int>& bag,int k){
        if(ind == cook.size()){
            int mx = 0;
            for(int i =0;i<bag.size();i++){
                mx = max(mx,bag[i]);
            }
            ans = min(ans,mx);
            return ;
        }
        
        
        for(int i=0;i<bag.size();i++){
            if(bag[i] + cook[ind] < ans){
                bag[i]+= cook[ind];
                search(cook,ind+1,bag,k);
                bag[i]-=cook[ind];   
            }  
        }
        
        return ;    
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        ans = INT_MAX;
        vector<int> bag(k,0);
        search(cookies,0,bag,k);
        return ans;  
    }
};