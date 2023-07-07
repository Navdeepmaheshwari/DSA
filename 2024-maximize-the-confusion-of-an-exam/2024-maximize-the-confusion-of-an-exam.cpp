class Solution {
public:
    int maxConsecutiveAnswers(string ansKey, int k) {
       
        int n=ansKey.size();
        int ans=INT_MIN;
        int i=0,j=0,cnt=0;
        //  maximum substring of 'T' which contains k 'F'
        
        while(j<n){
            
            if(ansKey[j]=='F'){
                cnt++;
            }
            
            while(cnt>k){
                if(ansKey[i]=='F'){
                    cnt--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        
        //  maximum substring of 'F' which contains k 'T'
        cnt=0,j=0,i=0;
        
         while(j<n){
            
            if(ansKey[j]=='T'){
                cnt++;
            }
            
            while(cnt>k){
                if(ansKey[i]=='T'){
                    cnt--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};