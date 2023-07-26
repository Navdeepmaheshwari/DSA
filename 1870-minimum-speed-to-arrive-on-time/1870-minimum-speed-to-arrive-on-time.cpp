class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        if(hour <= n-1) return -1; //min speed 1 k liye equal cahiye;
        
        // given that not exceed 10^7 so range is 1 to 1e7
        int l=1 , r=1e7;
        int minSpeed=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
           
            double time =0;
            
            //n-1 tk ka ceil lena h
            for(int i=0 ; i<n-1 ; i++) time += ceil((double)dist[i]/mid); 
            
             // last ka as it is
            time += (double)dist[n-1]/mid;
           
          
            if(time <= hour)
            {
                minSpeed=mid; 
                r=mid-1;
            }
            else l = mid+1;
        }
        return minSpeed;
        
    }
};