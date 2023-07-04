class Solution {
public:
    vector<int>nextSmaller(vector<int>& heights,int n){
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        
        for(int i=n-1;i>=0;i--){
            int curr=heights[i];
            
            while(st.top()!=-1&& heights[st.top()]>=curr){
                st.pop();
            }
            
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    
     vector<int>prevSmaller(vector<int>& heights,int n){
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        
        for(int i=0;i<n;i++){
            int curr=heights[i];
            
            while(st.top()!=-1&& heights[st.top()]>=curr){
                st.pop();
            }
            
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxArea=0;

        vector<int>next(n); //store indexes of next smaller
        next=nextSmaller(heights,n);
        
        vector<int>prev(n); //store indexes of prev smaller
        prev=prevSmaller(heights,n);
        
        for(int i=0;i<n;i++){
            int len=heights[i];
            
            if(next[i]==-1){
                next[i]=n;
            }
            int bre=next[i]-prev[i]-1;
            
            int curr=len*bre;
            maxArea=max(curr,maxArea);
        }
        
        return maxArea;
        
    }
};