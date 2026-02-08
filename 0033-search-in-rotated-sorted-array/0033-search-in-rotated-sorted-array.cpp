class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low+ (high-low)/2;

            // return if mid elemtn == target
            if(nums[mid] == target){
                return mid;
            }
            // chekc if the left half is sorted
            if(nums[low] <= nums[mid]){
                // if target lies in the left half serch there else search right
                if(nums[low] <= target && target < nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{ // the right half is sorted

                // if the target lies rihgt half search there else search left
                if(nums[mid] < target && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
            
        }
        return -1;
    }
};