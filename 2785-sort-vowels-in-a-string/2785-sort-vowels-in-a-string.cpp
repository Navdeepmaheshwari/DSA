class Solution {
public:
    bool isVowel(char&ch){
        
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
           ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') return true;
        
        return false;
    }
    string sortVowels(string s) {
        vector<char>v;
        int n=s.size();
        for(auto x:s){
            if(isVowel(x)){
                v.push_back(x);
            }
        }
        sort(v.begin(),v.end());
        int ind=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                s[i]=v[ind++];
            }
        }
        return s;
    }
};