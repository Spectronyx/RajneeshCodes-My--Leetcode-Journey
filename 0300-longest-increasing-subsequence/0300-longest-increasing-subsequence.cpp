class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &nums,int i,int prev){
        if(i == nums.size()) return 0;

        int skip = solve(nums,i+1,prev);

        int take = 0;

        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + solve(nums,i+1,i);
        }

        return max(skip,take);
    }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();

    //     dp.assign(n,vector<int>(n+1,-1));

    //     return solve(nums,0,-1);
    // }

        int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1);

        int ans = 1;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};