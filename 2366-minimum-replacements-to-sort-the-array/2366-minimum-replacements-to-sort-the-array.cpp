class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        int last = nums[n-1];
        long long ans = 0;
        // Traverse the array in reverse order
        for(int i = n-2; i >= 0; --i){
            if(nums[i] > last)
            {
                int t = nums[i] / last;  // Calculate how many times the element needs to be divided
                if (nums[i] % last) t++; // If there's a remainder, increment 't'
                last = nums[i] / t;  // Update 'last' for the next comparison
                ans += t - 1; // Add (t - 1) to 'ans' for the number of operations
            }
            else
            { 
                last = nums[i];
            }
        }
        return ans;
    }
};