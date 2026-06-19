class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int maxAltitude = INT_MIN;
        for(auto &g:gain){
            sum = sum+g;
            maxAltitude = max(maxAltitude,sum);
        }
        return maxAltitude > 0 ? maxAltitude: 0;
    }
};