class Solution {
public:
    long long minimumTime(vector<int>& time, int tot) {
        int n=time.size();
        // sort(time.begin(),time.end());
        long long low=1;
        // long long high=((long long)time[n-1])*((long long)tot);
        long long high=1e14; //maximum value of time[i]*maximum value of totalTrips
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long cntTrip=0;
            
            for(int i=0;i<n;i++){
                cntTrip+=mid/time[i];
            }
            if(cntTrip<tot){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};