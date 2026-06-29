class Solution {
public:
    vector<vector<int>> result;
    int n;
    void solve(vector<int> &nums,vector<int> &curr,vector<int> &visited){
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }

        for(int i = 0; i < n;i++){
            if(visited[i]){
                continue;
            }

            visited[i] = 1;
            curr.push_back(nums[i]);

            solve(nums,curr,visited);
            curr.pop_back();
            visited[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        vector<int> visited(n,0);
        solve(nums,curr,visited);
        return result;
    }
};