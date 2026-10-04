class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int N;

    void solve(vector<int> &curr,int i,int k,int target){
        if(k == 0 && target == 0){
            ans.push_back(curr);
            return;
        }

        if(target < 0 || i >= 9) return;

        curr.push_back(nums[i]);
        solve(curr,i+1,k-1,target-nums[i]);
        curr.pop_back();
        solve(curr,i+1,k,target);

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        N = n;
        vector<int> curr;
        solve(curr,0,k,n);
        return ans;
    }
};