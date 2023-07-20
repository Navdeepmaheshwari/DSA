class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
     
        int n=a.size();
        stack<int>st;
        for(int i=0;i<n;i++){

            if(st.empty()||a[i]>0){
                st.push(a[i]);
            }
            
            else{
            // pop out element which is less than or equal to top
               while(!st.empty()&&st.top()>0 && st.top()<abs(a[i])){
                    st.pop();
                }
                
                if(!st.empty()&& st.top()==abs(a[i])){
                    st.pop();
                }
                
                //neagtive neagtive don't collide so push
                else if(st.empty()||st.top()<0){
                    st.push(a[i]);
                }
                
            }
        }
        
        int sz=st.size();
        vector<int>ans(sz);
        for(int i=sz-1;i>=0;i--){
            ans[i]=st.top();st.pop();
        }
        return ans;
    }
};