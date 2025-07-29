class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // create a profit vector and initialize it as zero
        int n = prices.size();
        vector<int> profit(n,0);

        //set the maxPrice initially to last value;
        int maxPrice = prices[n-1];
        for(int i = n-2;i >= 0;i--){
            //update the maxPrice with each iteration
            maxPrice = max(maxPrice,prices[i]);

            //update teh profit
            profit[i] = max(profit[i+1],maxPrice - prices[i]);
        }

        // intitialize resutl
        int res = 0;
        int minPrice = prices[0];

        // traverse from left to right to get the actual profit
        for(int i = 1 ; i< n;i++){
            minPrice = min(minPrice,prices[i]);
            res = max(res,profit[i] + (prices[i] - minPrice));
        }
        return res;
    }
};