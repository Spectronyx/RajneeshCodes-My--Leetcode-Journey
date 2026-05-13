class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);
        
        // Process each symmetric pair
        for(int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            int sum = a + b;
            
            /*
             * For each pair, moves needed for target T:
             * T = a+b        → 0 moves
             * T in [1+min, limit+max]  → 1 move
             * T in [2, 2*limit]        → 2 moves
             */
            
            // Initially all targets need 2 moves
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;
            
            // Reduce to 1 move for possible range
            int left1 = min(a, b) + 1;          // Minimum with 1 move
            int right1 = max(a, b) + limit;     // Maximum with 1 move
            diff[left1]--;
            diff[right1 + 1]++;
            
            // Reduce to 0 moves for exact sum
            diff[sum]--;
            diff[sum + 1]++;
        }
        
        int ans = n;
        int curr = 0;
        
        // Prefix sum to get actual values
        for(int target = 2; target <= 2 * limit; target++) {
            curr += diff[target];
            ans = min(ans, curr);
        }
        
        return ans;
    }
};