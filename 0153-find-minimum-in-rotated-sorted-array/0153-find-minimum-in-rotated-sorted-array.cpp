class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low < high){
            int mid = low + (high -low)/2;

            //if the right half is sorted discard the left half
            if(nums[mid] > nums[high]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return nums[low];
    }
};