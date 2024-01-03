class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int res=0,prev=0;
        for(auto x:bank){
            int cnt=0;
            
            for(auto i:x){
                if(i=='1')cnt++;
            }
            
            if(cnt>0){
                
                res=res+cnt*prev;
                prev=cnt;
            }
        }
        return res;
    }
};