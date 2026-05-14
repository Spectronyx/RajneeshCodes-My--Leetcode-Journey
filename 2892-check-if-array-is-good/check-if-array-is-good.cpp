class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int n = maxi;
        
        if(nums.size() != n+1) return false;

        vector<int> freq(n+2,0);
        for(auto num: nums){
            if(num < 1 || num > n) return false;
            freq[num]++;
        }

        for(int i = 1;i < n;i++){
            if(freq[i] != 1) return false;
        }

        return freq[n] == 2;

        return false;
    }
};

// class Solution {
// public:
//     bool isGood(vector<int>& nums) {
//         int n = *max_element(nums.begin(),nums.end());
//         if(nums.size() != n+1) return false;
        
//        sort(nums.begin(),nums.end());
//        if(n<=0) return false;

//        for(int i = 0;i < n;i++){
//             if(nums[i] != i+1) return false;
//        }

//        return nums[n] = n;
//     }
// };