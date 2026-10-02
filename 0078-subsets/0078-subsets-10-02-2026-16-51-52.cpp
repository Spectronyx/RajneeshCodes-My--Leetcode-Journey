class Solution {
public:
    vector<vector<int>> ans;
    int N;

    void fn(vector<int> &nums,int i ,vector<int> st){
        if(i >= N){
            ans.push_back(st);
            return;
        }

        //choose
        st.push_back(nums[i]);
        fn(nums,i+1,st);
        //nochoose
        st.pop_back();
        fn(nums,i+1,st);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        N = nums.size();
        vector<int> st;
        fn(nums,0,st);

        return ans;
    }
};