class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nonZeroPos = 0;

        for(int i = 0;i < n;i++){
            if(nums[i] != 0){
                nums[nonZeroPos] = nums[i];
                if(i != nonZeroPos){
                    nums[i] = 0;
                }
                nonZeroPos++;
            }
        }
        
    }
};