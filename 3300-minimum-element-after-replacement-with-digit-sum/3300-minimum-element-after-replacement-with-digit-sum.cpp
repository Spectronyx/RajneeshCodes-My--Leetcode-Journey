class Solution {
public:
    int findSum(int n){
        int ans = 0;
        while(n){
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int minElement = INT_MAX;

        for(int i = 0;i < nums.size();i++){
            int sum = findSum(nums[i]);
            minElement = min(minElement,sum);
        }
        return minElement;
    }
};