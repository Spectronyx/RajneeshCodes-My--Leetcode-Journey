class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while( l< r){
            int mid = l+(r-l)/2;
            if(nums[mid] > nums[r]){
                // min in the ritght half
                l = mid+1;
            }else if(nums[mid] < nums[r]){
                r = mid;
            }else{
                // reducing the search space 
                // cannot decide where is the minimum;
                r = r-1;
            }
        }
        return nums[l];
    }
};