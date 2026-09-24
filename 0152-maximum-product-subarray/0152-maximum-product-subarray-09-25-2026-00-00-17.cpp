class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minSoFar = nums[0];
        int maxSoFar = nums[0];
        int result = nums[0];


        for(int i = 1;i < n;i++){
            int num = nums[i];

            int tempMax = max({num,num*maxSoFar,num*minSoFar});
            minSoFar = min({num,num*minSoFar,num*maxSoFar});
            maxSoFar = tempMax;

            result = max(maxSoFar,result);

        }
        return result;
    }
};