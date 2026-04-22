class Solution {
    void solve(vector<int> &nums,int i,int target,vector<int>& temp, vector<vector<int>>& ans){
        if(i == nums.size()){
            if (target == 0)
                ans.push_back(temp);
            return;
        }

        // take
        if(nums[i] <= target){
            temp.push_back(nums[i]);
            solve(nums,i,target-nums[i],temp,ans);
            temp.pop_back();
        }
        solve(nums,i+1,target,temp,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // using recursion apporach
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,0,target,temp,ans);
        return ans;
    }
};