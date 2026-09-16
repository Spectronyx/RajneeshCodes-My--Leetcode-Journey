class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrices = prices[0];
        int maxProfit = 0;
        int n = prices.size();

        for(int i = 0;i <n;i++){
            minPrices = min(minPrices,prices[i]);
            int profit = prices[i]-minPrices;
            maxProfit = max(profit,maxProfit);
        }
        return maxProfit;
    }
};