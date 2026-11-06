class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 1;

        vector<int> ans(n);

        for(int k = 0;k < n;k++){
            if(nums[k]%2 == 0){
                ans[i] = nums[k];
                i+= 2;
            }else{
                ans[j] = nums[k];
                j += 2;
            }
        }

        return ans;
    }
};