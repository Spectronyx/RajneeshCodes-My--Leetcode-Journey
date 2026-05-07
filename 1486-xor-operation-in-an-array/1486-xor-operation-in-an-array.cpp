class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        vector<int> nums;

        for(int i = 0;i< n;i++){
            nums.push_back(start+2*i);
        }

        for(auto num:nums){
            ans ^= num;
        }
        return ans;
    }
};