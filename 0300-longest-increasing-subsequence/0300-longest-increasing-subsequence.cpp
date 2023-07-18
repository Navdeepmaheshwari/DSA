class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int>v;
       v.push_back(a[0]);
       int len=1;
       
       for(int i=1;i<n;i++){
           
           if(a[i]>v.back()){
               v.push_back(a[i]);
               len++;
           }
           else{
               int ind=lower_bound(v.begin(),v.end(),a[i])-v.begin();
               v[ind]=a[i];
           }
       }
       return len;
    }
};