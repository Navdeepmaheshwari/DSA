class Solution {
public:
    int accountBalanceAfterPurchase(int p) {
        int r = p%10;
        if(r>=0 && r<5) p = p-r;
        else p = p + 10-r;
        return 100 - p;
    }
};