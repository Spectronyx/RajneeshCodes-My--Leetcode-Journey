class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        const int M = 1e9+7;
        sort(nums.begin(),nums.end());
        vector<long long> power(n);
        power[0] = 1;

        for(int i = 1;i < n;i++){
            power[i] = (2*power[i-1])%M;
        }

        int left = 0;
        int right = n-1;

        long long ans = 0;

        while(left <= right){
            if(nums[left]+nums[right] <= target){
                ans = (ans + power[right-left])%M;
                left++;
            }else {
                right--;
            }

        }

        return (int)ans;

    }
};