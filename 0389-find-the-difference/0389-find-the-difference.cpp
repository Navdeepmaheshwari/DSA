class Solution {
public:
    char findTheDifference(string s, string t) {
       int xorr=0;
        for(int i=0;i<s.size();i++){
            xorr=xorr^(s[i]-'a');
        }
        for(int i=0;i<t.size();i++){
            xorr=xorr^(t[i]-'a');
        }
        
        return xorr+'a';
    }
};