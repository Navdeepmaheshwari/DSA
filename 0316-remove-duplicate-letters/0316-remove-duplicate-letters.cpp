class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]=i; //storing the last index
        }
        
        stack<char>st;
        vector<bool>vis(26,0);
        for(int i=0;i<n;i++){
          
            if(vis[s[i]-'a'])continue;
            while(!st.empty() && st.top()>s[i] && i<mp[st.top()]){
                vis[st.top()-'a']=0;
                st.pop(); 
            }
            
            st.push(s[i]);
            vis[s[i]-'a']=1;
        }
        
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};