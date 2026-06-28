class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);

        for(auto idx = 2*n-1;idx >= 0;idx--){
            int i = idx%n;
            while(!st.empty() && nums[i] >= st.top()){
                st.pop();
            }

            if(st.empty()){
                ans[i] = -1 ;
            }else{
                ans[i] = st.top();
            }

            st.push(nums[i]);
        }
        
        return ans;
    }
};