class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high-low)/2;

            // if the element is found
            if(nums[mid] == target) return true;

            // edge case if three of them are equal and
            //  we cannot decide where to move
            if(nums[low] == nums[mid] && nums[mid] == nums[high] ){
                low++;
                high--;
                continue;
            }

            // if the left half is sorted
            if(nums[low] <= nums[mid]){
                //serch in the left else right
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid -1;
                }else{
                    low = mid + 1;
                }
            }else{
                //the right is sorted
                //search in the right half else search the left half
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};