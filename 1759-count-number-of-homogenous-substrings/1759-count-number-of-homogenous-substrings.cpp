class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 1, count = 1, m = 1e9 + 7;
    for(int i = 1; i < s.size(); ++i){
        count = (s[i] == s[i-1])?count + 1: 1;
        ans = (ans + count)%m;
    }
    return ans;
    }
};