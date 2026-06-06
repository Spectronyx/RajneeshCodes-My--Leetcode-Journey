class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightSum(n,0);
        vector<int> leftSum(n,0);
        
        int rSum = nums[n-1];
        for(int i = n-2;i >= 0;i--){
            rightSum[i] = rSum;
            rSum += nums[i];
        }

        int lSum = nums[0];
        for(int i = 1;i < n;i++){
            leftSum[i] = lSum;
            lSum += nums[i];
        }
        vector<int> ans;
        for(int i = 0;i < n;i++){
            ans.push_back(abs(leftSum[i]-rightSum[i]));
        }
        return ans;
    }
};