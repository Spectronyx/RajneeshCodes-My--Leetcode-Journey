class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0;
        int n = nums.length;
        int maxAns = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1){
                ans++;
                maxAns = Math.max(ans,maxAns);
            }else{
                ans = 0;
            }
        }
        maxAns = ans > maxAns ? ans: maxAns;
        return maxAns;
    }
}