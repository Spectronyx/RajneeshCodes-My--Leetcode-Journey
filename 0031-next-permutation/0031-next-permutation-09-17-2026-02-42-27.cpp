class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // find the pivot
        int i = n-2;

        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }

        // find the element just greater than the pivot
        if(i >= 0){
            int j = n-1;
            while(j >= 0 && nums[j] <= nums[i]){
                j--;
            }

            swap(nums[i],nums[j]);
        }

        //reverse the suffix

        reverse(nums.begin()+i+1,nums.end());
    }
};