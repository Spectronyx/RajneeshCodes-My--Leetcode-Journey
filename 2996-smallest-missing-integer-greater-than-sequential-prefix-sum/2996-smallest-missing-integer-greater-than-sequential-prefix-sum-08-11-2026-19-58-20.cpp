#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // Step 1: Find the longest sequential prefix starting at index 0
        int prefixSum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            // Check if the current element continues the sequential sequence
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];
            } else {
                // Break immediately when the sequential sequence stops
                break;
            }
        }

        // Step 2: Store all elements of the array in a hash set for O(1) lookups
        std::unordered_set<int> uniqueNumbers(nums.begin(), nums.end());

        // Step 3: Increment the prefix sum until an integer is found that is missing from the set
        while (uniqueNumbers.count(prefixSum)) {
            prefixSum++;
        }

        return prefixSum;
    }
};
