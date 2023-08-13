class Solution {
public:
    int hammingDistance(int x, int y) {
        int sum=0;
         int XOR=x^y;       
        while(XOR)
        {
            sum+=XOR&1;
            XOR= XOR>>1;     
        }
                
        return sum;
    }
};