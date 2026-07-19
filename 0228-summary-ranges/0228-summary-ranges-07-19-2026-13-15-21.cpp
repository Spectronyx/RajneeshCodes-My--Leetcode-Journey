class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> ans;

        if (nums.empty())
            return ans;

        int start = nums[0];

        string mid = "->";

        for (int i = 1; i <= nums.size(); i++) {

            if (i == nums.size() ||
               1LL* nums[i] - nums[i - 1] != 1) {

                int end = nums[i - 1];

                if (start != end) {
                    ans.push_back(
                        to_string(start) + mid +
                        to_string(end)
                    );
                }
                else {
                    ans.push_back(
                        to_string(start)
                    );
                }

                if (i < nums.size()) {
                    start = nums[i];
                }
            }
        }

        return ans;
    }
};