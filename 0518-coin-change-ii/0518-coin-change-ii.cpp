class Solution {
public:
    vector<vector<int>> dp;
    int solve(int amount, vector<int>& coins,int i){
        if(amount == 0) return 1;
        if(amount < 0) return 0;
        if(i >= coins.size()) return 0;
        if(dp[amount][i] != -1){
            return dp[amount][i];
        }
        int take = solve(amount-coins[i],coins,i);
        int skip = solve(amount,coins, i+1);

        return dp[amount][i] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
            dp.assign(amount+1, vector<int>(coins.size(), -1));
        return solve(amount,coins,0);
    }
};