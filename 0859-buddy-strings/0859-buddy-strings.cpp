class Solution {
public:
    bool buddyStrings(string s, string goal) {
         // check same length
        if(s.size()!=goal.size())return false;
        int n=s.size();
        
        // if strings are equal - check if there is a double to swap
       if(s==goal){
           set<char>st(s.begin(),s.end());
           return st.size()<goal.size();
       }
        
         // count differences between strings
        vector<int>diff;
        for(int i=0;i<n;i++){
            
            if(s[i]!=goal[i]){
                diff.push_back(i);
                
                if(diff.size()>2)return false;
            }
        }
        
        // not exactly two differences
        if(diff.size()!=2)return false;
        
        // check if can be swapped
        if(s[diff[0]]==goal[diff[1]]&&s[diff[1]]==goal[diff[0]])return true;
        
        return false;
    }
};