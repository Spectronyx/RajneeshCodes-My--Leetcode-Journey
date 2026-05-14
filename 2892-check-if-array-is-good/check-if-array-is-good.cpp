// class Solution {
// public:
//     bool isGood(vector<int>& nums) {
//         int maxi = *max_element(nums.begin(),nums.end());
//         int n = maxi;
        
//         if(nums.size()-1 ==  maxi){
//             int sum = 0;
//             for(auto num: nums){
//                 sum += num;
//             }
//             int required_sum = (n*(n+1))/2;
//             if(sum == required_sum) return true;
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(),nums.end());
        if(nums.size() != n+1) return false;
        
       sort(nums.begin(),nums.end());
       if(n<=0) return false;

       for(int i = 0;i < n;i++){
            if(nums[i] != i+1) return false;
       }

       return nums[n] = n;
    }
};