class Solution {
public:
    int operation(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }
    
    vector<int> diffWaysToCompute(string exp) {
        int n=exp.size();
        vector<int>ans;
      
         if (exp.size() == to_string(stoi(exp)).size()) 
             return vector<int>({stoi(exp)});
        
        for(int i=0;i<n;i++){
            
            if(isdigit(exp[i])){
               continue;
            }
            
            vector<int>left=diffWaysToCompute(exp.substr(0,i));
            vector<int>right=diffWaysToCompute(exp.substr(i+1));
            
            for(auto x:left){
                
                for(auto y:right){
                    int val = operation(x, y, exp[i]);
                    ans.push_back(val);  
                }
            }  
        }
        return ans;
    }
};