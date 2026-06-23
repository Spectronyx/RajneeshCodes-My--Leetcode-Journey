class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int currSum = 0;
        for(int i = 0;i < k;i++){
            currSum += nums[i];
        }
        int maxSum = currSum;

        for(int right = k;right < nums.size();right++){
            currSum = currSum + nums[right] - nums[right-k];
            maxSum = max(maxSum,currSum);
        }
        return (double)maxSum/k;
    }
};