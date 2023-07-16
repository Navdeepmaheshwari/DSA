class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        //left ka max element  right k min element s chota hona chahiye
        int n=nums.size();
        int ind=0;
        vector<int>prefix(n),suffix(n);
        //in prefix we store max element of array till index i;
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }
        
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        
        for(int i=0;i<n-1;i++)
        {
            if(prefix[i]<=suffix[i+1])
            {
                ind=i;
                break;
            }
        }
        return ind+1;
    }
};