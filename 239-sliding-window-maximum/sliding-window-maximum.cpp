class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //using monotonic queue
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for(int i = 0;i < n;++i){
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }

            //remove the element forom the back to maintain the decreasing order
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();

            dq.push_back(i);

            //append the answer when we have the complete window
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
   }
};