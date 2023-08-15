class Solution {
public:
    int romanToInt(string s) {
     
    unordered_map<char, int> romint = {{'I', 1}, {'V', 5},{'X', 10},{'L', 50},
  {'C', 100},{'D', 500},{'M', 1000}};
        
   int sum = 0;
  for(int i = 0; i < s.length(); i++){

        if(romint[s[i]] >= romint[s[i+1]]){
          sum = sum + romint[s[i]]; 
        }

        else{
          sum = sum - romint[s[i]];  
        }
  }
  return sum;
    }
};