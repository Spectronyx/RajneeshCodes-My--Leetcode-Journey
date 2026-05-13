class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;

        // circular hai, isiliye 2 passes
        for(int i = 0;i < 2*n;i++){
            int idx = i%n;
            // current element next greater hai stack ke indices ke liye
            while(!st.empty() && nums[st.top()] < nums[idx] ){
                ans[st.top()] = nums[idx];
                st.pop();
            }

            if(i < n){
                st.push(idx);
            } 

        }
        return ans;
    }
};