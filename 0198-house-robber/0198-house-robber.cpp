class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <= 2) return *max_element(nums.begin(),nums.end());

        int prev1 = max(nums[0],nums[1]);
        int prev2 = nums[0];

        for(int i = 2;i < n;i++){
            int curr = max(prev1,prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};