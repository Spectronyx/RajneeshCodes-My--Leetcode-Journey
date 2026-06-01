class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        if(cost.size() == 1) return cost[0];

        int minVal = 0;
        int n = cost.size();
        for(int i = 0;i < n;i++){

            if(i %3 != 2)
            minVal += cost[i];
        }
        return minVal;
    }
};