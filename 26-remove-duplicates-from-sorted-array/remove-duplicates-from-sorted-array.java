class Solution {
    public int removeDuplicates(int[] nums) {
       int n = nums.length;
       
       if(n == 0) return 0;

       int j = 0;
       for(int i = 1;i < n;i++){
            // agar naya element mila toh
            if(nums[i] != nums[j]){
                j++;
                if(i != j)
                nums[j] = nums[i];
            }
       }
       return j+1;
    }
}