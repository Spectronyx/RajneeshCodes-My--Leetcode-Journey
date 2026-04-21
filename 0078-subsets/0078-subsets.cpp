class Solution {
public:
    void solve(vector<int> &nums,int i,vector<vector<int>>& ans,vector<int> temp){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
    // take
        temp.push_back(nums[i]);
        solve(nums,i+1,ans,temp);
        temp.pop_back();
        solve(nums,i+1,ans,temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;
        solve(nums,i,ans,{});
        return ans;
    }
};