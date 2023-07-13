class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_buy = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            min_buy = min(min_buy, prices[i]);
            max_profit = max(max_profit, prices[i] - min_buy);
            // cout<<max_profit<<endl;
        }
        return max_profit;
    }
};