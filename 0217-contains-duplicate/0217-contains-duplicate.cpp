class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        stable_sort(nums.begin(),nums.end());
        // wihtut using heashset
        for(int i = 1;i < nums.size();i++){
            if(nums[i-1] == nums[i]) return true;
        }
        return false;
    }
};