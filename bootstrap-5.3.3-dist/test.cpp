#include <vector>

class Solution {
public:
    int arrayOperations(int n, std::vector<int>& arr) {
        const int MOD = 1e9 + 7;
        
        // Define the maximum possible bit position
        const int MAX_BITS = 30;
        
        // Frequency array to count the number of times each bit is set across all array elements
        std::vector<int> bit_count(MAX_BITS + 1, 0);
        
        // Count the frequency of each bit position in the array
        for (int num : arr) {
            for (int i = 0; i <= MAX_BITS; i++) {
                if (num & (1 << i)) {
                    bit_count[i]++;
                }
            }
        }
        
        int ans = 0;
        
        // Iterate through each bit position
        for (int i = 0; i <= MAX_BITS; i++) {
            // Calculate the total number of pairs that can be formed with the current bit position set
            // This is the combination nC2
            if (bit_count[i] > 1) {
                int num_pairs = (bit_count[i] * (bit_count[i] - 1) / 2) % MOD;
                
                // The contribution of this bit position to the final answer
                int bit_contribution = (num_pairs * (1 << i)) % MOD;
                
                // Add the bit contribution to the final answer
                ans = (ans + bit_contribution) % MOD;
            }
        }
        
        return ans;
    }
};
