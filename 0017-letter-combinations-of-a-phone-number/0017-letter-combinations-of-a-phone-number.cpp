map<char,string>mp(
            {{'2',"abc"},{'3',"def"},{'4',"ghi"},
            {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
            {'8',"tuv"},{'9',"wxyz"}}
        );
class Solution {
public:
    void allCombination(string digits,vector<string>&res,int i,string ans,int n){
        
        if(i==n) res.push_back(ans);
        else{
            string temp=mp[digits[i]];
                for(int j=0;j<temp.size();j++)
                {
                  allCombination(digits,res,i+1,ans+temp[j],n);
                }
            }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string>res;
        int n=digits.size();
        if(n == 0)return res;
        allCombination(digits,res,0,"",n);
        return res;
        
    }
};