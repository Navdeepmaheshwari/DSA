class Solution {
public:
    int maxProduct(vector<int>& nums) {
         priority_queue<int> maxh;
        for(auto curr:nums) maxh.push(curr);
        int a = maxh.top();
        maxh.pop();;
        int b = maxh.top();
        return (a-1)*(b-1);
    }
};