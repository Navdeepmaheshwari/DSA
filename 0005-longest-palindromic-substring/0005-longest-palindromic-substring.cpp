class Solution {
public:
    vector<int> solve(string s,int p,int q,int n){
        int i=p,j=q;
        int ansx= 0,ansy=0;
         while(i>=0&&j<n){
             if(s[i]==s[j]){
                 ansx=i;
                 i--;
                 ansy=j;
                 j++;
             }
             else break;
         }
    return {ansx,ansy};
    }
    
    string longestPalindrome(string s) {
        
        int mid=0;
        int n=s.size();
        if(n<=1) return s;
        int res=1;
        int maxlen=0;
        string ans="";
       for(int i=0;i<n;i++){
           vector<int> temp1;
           vector<int> temp2;
           temp1= solve(s,i,i,n);
           temp2= solve(s,i,i+1,n);
           int len1= temp1[1]-temp1[0]+1;
           int len2= temp2[1]-temp2[0]+1;
           if(len1>len2){
               if(len1>maxlen){
                   ans= s.substr(temp1[0],len1);
                   maxlen=len1;
               }
           }
           else{
               if(len2>maxlen){
                   ans= s.substr(temp2[0],len2);
                   maxlen= len2;
               }
           }
       }
        return ans;
    }
};