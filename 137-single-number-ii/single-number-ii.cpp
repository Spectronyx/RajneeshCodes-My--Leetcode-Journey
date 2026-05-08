class Solution {
public:
    // int singleNumber(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    //     for(auto num: nums){
    //         mp[num]++;
    //     }

    //     for(auto &p : mp){
    //         if(p.second == 1){
    //             return p.first;
    //         }
    //     }
    //     return -1;
    // }

    //  int singleNumber(vector<int>& nums) {
    //     int ans = 0;
        
    //     // Check each of the 32 bits
    //     for(int i = 0; i < 32; i++) {
    //         int count = 0;
            
    //         // Count how many numbers have this bit set
    //         for(int num : nums) {
    //             if(num & (1 << i)) {
    //                 count++;
    //             }
    //         }
            
    //         // If count is not multiple of 3, this bit belongs to the single number
    //         if(count % 3) {
    //             ans |= (1 << i);
    //         }
    //     }
        
    //     return ans;
    // }

    int singleNumber(vector<int>& nums){
        sort(nums.begin(),nums.end());
        for(int i = 1;i < nums.size();i = i+3){
            if(nums[i-1] != nums[i]) return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};