class Solution {
public:
    void solve(int idx,vector<int> &arr,vector<int>& temp,vector<vector<int>> &ans){
        ans.push_back(temp);

        for(int i = idx;i < arr.size();i++){
            //skip the duplicates
            if(i > idx && arr[i] == arr[i-1]) continue;

            temp.push_back(arr[i]);
            solve(i+1,arr,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0,nums,temp,ans);
        return ans;
    }
};