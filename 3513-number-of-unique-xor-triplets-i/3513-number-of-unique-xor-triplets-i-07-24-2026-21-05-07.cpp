#include <vector>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        
        // Base cases for small permutations
        if (n <= 2) {
            return n;
        }
        
        // Find the most significant bit (MSB) position of n
        // __builtin_clz finds the number of leading zeros
        int msb_power_of_two = 1 << (31 - __builtin_clz(n));
        
        // The total number of unique values is 2^(msb + 1)
        return msb_power_of_two * 2;
    }
};
