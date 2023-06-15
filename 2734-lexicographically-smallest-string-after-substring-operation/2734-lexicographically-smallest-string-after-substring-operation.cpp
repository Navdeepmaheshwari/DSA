class Solution {
public:
    string smallestString(string s) {
     
        int n=s.size();
        int ind=0;
    // skip if 'a' is occuring as substring from starting
      while(ind<n&&s[ind]=='a'){
          ind++;
      }
        
    // if reaches to last so we have to do exactly 1 operation so just change last one
        if(ind==n){
            s[n-1]='z';
        }
        
        while(ind<n&&s[ind]!='a'){
            s[ind]-=1;
            ind++;
        }
        return s;
    }
};