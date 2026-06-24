// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n =nums.size();

//         vector<bool> dp(n+1,false);

//         dp[n-1] = true;

//         for(int i = n-2;i>= 0;i--){
//             for(int jump = 1;jump <= nums[i];jump++){
//                 if(i+jump < n && dp[i+jump]){
//                     dp[i] = true;
//                     break;
//                 }
//             }

//         }
//         return dp[0];
//     }
// };

class Solution {
public:
    bool canJump(vector<int> &nums){
        int maxReach = 0;
        for(int i = 0;i < nums.size();i++){
            if(i > maxReach){
                return false;
            }
            maxReach = max(maxReach,nums[i]+i);
        }
        return true;
    }
};