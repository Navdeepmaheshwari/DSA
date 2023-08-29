class Solution {
public:
    int bestClosingTime(string cus) {
        int n=cus.size();
        int cntN=0;
        int cntY=0;
        for(auto x:cus){
            
            if(x=='Y'){
                cntY++;
            }
            else{
                cntN++;
            }
            
        }
        if(cntY==n)return n;
        if(cntN==n)return 0;
        int loss = INT_MAX;
        int ans =0;
       
        for(int i=0;i<n;i++){
            int res=cntY+cntN;
            if(loss>res){
                ans=i;
                loss=res;
            }    
            if(cus[i]=='Y'){
                cntY--;
            }else{
                cntN++;
            }
        }
        int x = cntY+cntN;
        if(loss>x){
            ans  = n;
        }
        return ans;
    }
    
};