class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minSoFar = prices[0];
        int n = prices.size();

        for(int i = 1;i < n;i++){
            minSoFar = min(minSoFar,prices[i]);

            maxprofit = max(maxprofit,prices[i]-minSoFar);
        }

        return maxprofit;
    }
};