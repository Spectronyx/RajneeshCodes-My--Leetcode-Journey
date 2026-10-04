class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void solve(vector<int> &candidates,vector<int> &res,int idx,int target){
        if(target == 0){
            ans.push_back(res);
        }

        for(int i = idx;i<n;i++){
            if(candidates[i]>target){
                break;
            }

            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }

            res.push_back(candidates[i]);
            solve(candidates,res,i+1,target-candidates[i]);
            res.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> res;
        sort(candidates.begin(),candidates.end());
        solve(candidates,res,0,target);
        return ans;
    }
};