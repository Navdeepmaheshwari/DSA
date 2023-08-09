class Solution {
public:
    int cntPairs(vector<int>&nums,int p,int currDiff){
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            
            if(nums[i+1]-nums[i]<=currDiff){
                cnt++;
                i++;//to avoid repeatation
            }
        }
        return cnt;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        int lo=0,hi=nums[n-1]-nums[0];  //range of difference
        int res=0;
        while(lo<=hi){
            
            int mid=lo+(hi-lo)/2;
            int cnt=cntPairs(nums,p,mid);
            
            if(cnt>=p){
                res=mid;hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return res;   
    }
};