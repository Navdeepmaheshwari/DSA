class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0 ;
        unordered_map<char, int>mp;
        for(char x:chars){
            mp[x]++;
        }
        for(string word:words){
        int i = 0;
        unordered_map<char, int>temp = mp;
           for(; i<word.size(); i++){
               if(temp[word[i]]){
                   temp[word[i]]--;
               }else{
                   break;
               }
           }
           if(i==word.size()) ans += word.size();
        }
        return ans;
    }
};