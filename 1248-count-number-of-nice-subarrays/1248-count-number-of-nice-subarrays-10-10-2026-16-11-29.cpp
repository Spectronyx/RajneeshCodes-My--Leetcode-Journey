class Solution {
public:
    int atMost(vector<int> &nums,int k){
        int n = nums.size();
        int left = 0;
        int ans = 0;
        int odds = 0;


        for(int right = 0;right < n;right++){
            if((nums[right]%2) != 0) odds++;


            while(odds > k){
                if(nums[left]%2 != 0) odds--;
                left++;
            }

            ans += (right-left+1);
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};