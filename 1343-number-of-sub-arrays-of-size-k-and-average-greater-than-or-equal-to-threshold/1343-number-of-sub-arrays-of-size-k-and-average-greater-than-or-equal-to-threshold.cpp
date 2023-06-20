class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int n=arr.size();
        int cnt=0;
        vector<int>presum(n+1,0);
        for(int i=1;i<=n;i++){
            presum[i]=presum[i-1]+arr[i-1];
        }
            for(auto x:presum){
            cout<<x<<" ";
        }
        cout<<endl;
        
        for(int i=k;i<=n;i++){
            
            int avg=(presum[i]-presum[i-k])/k;
            if(avg>=threshold)cnt++;
        }
        
        return cnt;
    }
};