#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // Step 1: Filter unique values and sort them
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        int u_size = nums.size();
        
        // Track whether an element exists in our unique set
        // Elements are <= 1500, so an array of size 2048 is safe
        vector<bool> has_element(2048, false);
        for (int val : nums) {
            has_element[val] = true;
        }
        
        // Step 2: Track frequencies of pairwise XOR values
        // Max possible XOR sum for values <= 1500 is 2047
        vector<int> pairs_count(2048, 0);
        for (int i = 0; i < u_size; ++i) {
            for (int j = i + 1; j < u_size; ++j) {
                int s = nums[i] ^ nums[j];
                pairs_count[s]++;
            }
        }
        
        // Step 3: Identify all possible unique triplet XOR values
        vector<bool> target_triplets(2048, false);
        
        // Single element cases (x ^ x ^ x = x) are covered initially
        for (int val : nums) {
            target_triplets[val] = true;
        }
        
        // Check for three distinct element triplets (x ^ y1 ^ y2)
        for (int x : nums) {
            for (int s = 0; s < 2048; ++s) {
                if (pairs_count[s] > 0) {
                    int y = s ^ x;
                    
                    // Check if 'x' was counted in any pairs making up 's'
                    bool is_x_in_pair = (y < 2048 && has_element[y] && y != x);
                    
                    // Deduct 1 pair configuration if 'x' was part of it
                    int available_pairs = pairs_count[s] - (is_x_in_pair ? 1 : 0);
                    
                    // If pairs remain, a valid distinct triplet exists
                    if (available_pairs > 0) {
                        target_triplets[s ^ x] = true;
                    }
                }
            }
        }
        
        // Step 4: Count the total unique XOR results found
        int unique_count = 0;
        for (int i = 0; i < 2048; ++i) {
            if (target_triplets[i]) {
                unique_count++;
            }
        }
        
        return unique_count;
    }
};
