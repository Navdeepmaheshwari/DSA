class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int diff=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++){
            diff=min(diff,arr[i+1]-arr[i]);
        }
    
        // cout<<diff<<endl;
        int cnt=0;
        vector<vector<int>>ans;
        for(int i=0;i<n-1;i++){
           
            if((arr[i+1]-arr[i])==diff){
                ans.push_back({arr[i],arr[i+1]});
                cnt++;
            }  
        }
        // cout<<cnt<<endl;
        return ans;
    
    }
};