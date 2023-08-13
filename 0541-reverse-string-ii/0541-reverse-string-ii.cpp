class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size()-1;
        int i=0;
        string ans="";
        while(true){
            
            int j=min(n,i+k-1);
            
            while(j>=i){
                ans+=s[j];
                j--;
            }
            
            for(int l=i+k;l<i+2*k;l++){
               
                if (l > n) return ans; // finished reversal
                ans+=s[l];
            }
            
            i+=2*k;
        }
        
        return ans;
    }
};