class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void solve(vector<int> & candidates,vector<int> &res, int i,int target){
        if(target == 0){
            ans.push_back(res);
            return;
        }

        if(target <0 || i >= n){
            return;
        }
        res.push_back(candidates[i]);
        solve(candidates,res,i,target-candidates[i]);
        res.pop_back();
        solve(candidates,res,i+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();

        vector<int> res;
        solve(candidates,res,0,target);
        return ans;

    }
};