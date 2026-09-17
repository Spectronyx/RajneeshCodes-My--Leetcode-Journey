class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int lastSmallest = INT_MIN;
        int currLen = 0;
        int maxLen = 1;
        if(n == 0) return 0;


        for(int i = 0;i < n;i++){
            if(lastSmallest == nums[i]){
                continue;
            }
            if(lastSmallest == nums[i]-1){
                currLen += 1;
            }else if(lastSmallest != nums[i]-1){
                currLen = 1;
            }
            lastSmallest = nums[i];
            maxLen = max(maxLen,currLen);
        }
        return maxLen;
    }
};