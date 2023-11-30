class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;  // Initialize a variable to store the final result
        int k = 0;    // Initialize a variable to keep track of the current bit position
        int mask = 1; // Initialize a mask to check each bit of the number
        
        // Iterate through each bit of the number from right to left
        while (mask <= n) {
            // Check if the k-th bit of the number n is set (equal to 1)
            if ((n & mask) != 0) {
                // If the k-th bit is set, update 'ans' using the formula for the number of one-bit operations
                ans = (1 << (k + 1)) - 1 - ans;
            }
            
            mask <<= 1; // Move the mask to the left to check the next bit
            k++;        // Increment the bit position counter
        }
        
        return ans; 
    }
};