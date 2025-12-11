class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> res;
        sort(begin(nums),end(nums));

        //cumulative sum
        for(int i =1;i < n;i++){
            nums[i] += nums[i-1];
        }

        for(int query: queries){
            int count = upper_bound(begin(nums),end(nums),query) - nums.begin();
            res.push_back(count);
        }
        return res;
    }
};