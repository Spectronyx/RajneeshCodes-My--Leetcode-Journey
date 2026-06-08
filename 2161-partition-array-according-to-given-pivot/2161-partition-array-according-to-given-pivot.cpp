class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> larger;
        int n = nums.size();
        int count = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i] < pivot){
                smaller.push_back(nums[i]);
            } else if(nums[i]>pivot){
                larger.push_back(nums[i]);
            }
            else count++;
        }

        int j = -1;
        for(int i = 0;i< smaller.size();i++){
            nums[++j] = smaller[i];
        }
        for(int i = 0;i < count;i++){
            nums[++j] = pivot;
        }
        for(int i = 0;i < larger.size();i++){
            nums[++j] = larger[i]; 
        }

        return nums;
    }
};