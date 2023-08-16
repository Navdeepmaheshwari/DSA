class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();  
        vector<int> result;
        if (k == 0) return result;
        multiset<int>st;
        for (int i = 0; i < n; i++) {
            if (i >= k)
            {
                //erase  element not by value by finding iterator of that value
                st.erase(st.find(nums[i-k]));
            }
            st.insert(nums[i]);
            if (i >= k-1)
                result.push_back(*st.rbegin()); //add 1st element
        }
        
        return result;
    }
};