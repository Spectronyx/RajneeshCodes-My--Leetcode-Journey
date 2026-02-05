class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using kadane
        int n = nums.size();
        int maxEnd = nums[0];
        int res = nums[0];

        for(int i = 1;i < n;i++){
            maxEnd = max(maxEnd+ nums[i], nums[i]);

            res = max(maxEnd,res);
        }
        return res;
    }
};