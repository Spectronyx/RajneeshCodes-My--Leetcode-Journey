class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     int maxlength = 1;
    //     vector<int> t(nums.size(),1);
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         for (int j = 0; j < i; j++)
    //         {
    //             if(nums[i] > nums[j]){
    //                 t[i] = max(t[i],t[j]+1);
    //                 maxlength = max(maxlength,t[i]);
    //             }
    //         }
            
    //     }
    //     return maxlength;
    // }

    int lengthOfLIS(vector<int> &nums){
        int n = nums.size();

        vector<int> sorted;

        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(begin(sorted),end(sorted),nums[i]);//just greater than or equal to
            // *it = element
            if(it == end(sorted)){
                sorted.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
        }
        return sorted.size();
    }
};