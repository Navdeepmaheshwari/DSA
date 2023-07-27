class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
        long long sum=0;
        for(auto x:bat){
            sum+=x;
        }
        
        long long low = 0, high =sum/n ;
        long long ans=0;
        while(low <= high){
            long long mid = low+(high-low)/2;
            long long time=0;
            for(int t : bat) time += min((long long)t,mid);

            if(mid*n <= time)
            {
                ans=mid;
                low = mid+1;
             }
            else 
            {
                high = mid-1;
            }
        }
        return ans;
        
    }
};