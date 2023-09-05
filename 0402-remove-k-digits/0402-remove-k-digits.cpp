class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()<=k)return "0";
        
        stack<char>st;
        
        for(auto x:num){
            
            while(!st.empty()&&st.top()>x&&k>0){
                st.pop();
                k--;
            }
            
            st.push(x);
        }
        
        if(k) {
            while(k--&&!st.empty()){
                st.pop();
            }
        }
        
        stack<char>temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        while(temp.size()!=1&&temp.top()=='0'){
            temp.pop();
        }
        
        // if(temp.size()==0)return "0";
        string ans="";
        while(!temp.empty()){
          ans+=temp.top();
            temp.pop();
        }
        return ans;
    }
};