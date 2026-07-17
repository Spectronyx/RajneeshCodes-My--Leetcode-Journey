#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // Find the maximum element to bound our frequency array
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Count frequencies of each number in nums
        vector<long long> count(max_val + 1, 0);
        for (int x : nums) {
            count[x]++;
        }
        
        // gcd_count[i] will store the exact number of pairs with GCD equal to i
        vector<long long> gcd_count(max_val + 1, 0);
        
        // Work backwards from max_val to 1
        for (int i = max_val; i >= 1; i--) {
            long long multiples = 0;
            
            // Count how many numbers in the array are multiples of i
            for (int j = i; j <= max_val; j += i) {
                multiples += count[j];
            }
            
            // Total pairs formed by multiples of i
            long long total_pairs = (multiples * (multiples - 1)) / 2;
            
            // Subtract pairs that have a strictly larger common multiple (e.g., 2*i, 3*i...)
            for (int j = 2 * i; j <= max_val; j += i) {
                total_pairs -= gcd_count[j];
            }
            
            gcd_count[i] = total_pairs;
        }
        
        // Build prefix sums of the pair counts to locate queries efficiently
        vector<long long> prefix_sums(max_val + 1, 0);
        for (int i = 1; i <= max_val; i++) {
            prefix_sums[i] = prefix_sums[i - 1] + gcd_count[i];
        }
        
        // Answer each query using binary search
        vector<int> ans;
        for (long long q : queries) {
            // upper_bound finds the first index where prefix sum is strictly greater than q
            auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            ans.push_back(distance(prefix_sums.begin(), it));
        }
        
        return ans;
    }
};
