class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u','A','I','E','O','U'};
        int i=0,j=s.size()/2,ans=0;
        while(j<s.size())
        {
            if(set.find(s[i])!=set.end()) ans++;
            if(set.find(s[j])!=set.end()) ans--;
            i++;
            j++;
        }
        if(ans==0)return true;
        return false;
    }
};