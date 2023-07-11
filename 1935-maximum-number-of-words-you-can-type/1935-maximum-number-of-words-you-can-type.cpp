class Solution {
public:
    int canBeTypedWords(string text, string broken) {
        unordered_set<char>st;
        for(auto x:broken){
            st.insert(x);
        }
        
        int cnt=0;
        string temp="";
        bool flag=false;
        int n=text.size();
        for(int i=0;i<n;i++){
            if(text[i]==' '){
                for(auto t:temp){
                    if(st.find(t)!=st.end()){
                        flag=true;
                    }
                }
                if(!flag)cnt++;
                temp="";
                flag=false;
            }
            else{
                temp+=text[i];
            }
        }
        
        for(auto t:temp){
           if(st.find(t)!=st.end()){
                 flag=true;
           }
        }
        if(!flag)cnt++;
        return cnt;
    }
};