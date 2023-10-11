class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
         vector<int> s, e; 
        for (auto a : flowers) {
            s.push_back(a[0]);
            e.push_back(a[1]);
        }

        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        vector<int> ans; 

        for (auto a : people) {
           
            auto i = upper_bound(s.begin(), s.end(), a);
            auto j = lower_bound(e.begin(), e.end(), a);

            int c = i - s.begin(); 
            int d = j - e.begin(); 
            ans.push_back(c - d); 
        }
        return ans; 
    }
};