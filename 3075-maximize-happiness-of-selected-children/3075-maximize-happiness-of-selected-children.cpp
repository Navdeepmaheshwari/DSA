class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long totalHappinessSum = 0;
       
        for(int i = 0; i < k; i++) {

            totalHappinessSum += max(happiness[i] - i, 0);   
        }
        
        return totalHappinessSum;
    }
};