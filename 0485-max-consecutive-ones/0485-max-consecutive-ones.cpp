class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int maxLen = 0;

        // while(right < n){
        //     if(nums[right] != 1){
        //         left = right+1;
        //         right++;
        //     }else{
        //         maxLen = max(maxLen,right-left+1);
        //         right++;
        //     }
        // }

        for(right = 0;right<n;right++){
            if(nums[right] == 0){
                left = right + 1;
            }
            maxLen = max(maxLen,right-left+1);
        }

        return  maxLen;
    }
};