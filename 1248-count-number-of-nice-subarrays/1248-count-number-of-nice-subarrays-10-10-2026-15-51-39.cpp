class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int oddCount = 0;
        int result = 0;

        mp[oddCount] = 1;

        for(int i = 0;i < nums.size();i++){
            if(nums[i]%2){
                oddCount++;
            }

            if(mp.count(oddCount-k)){
                result += mp[oddCount-k];
            }
            
            mp[oddCount]++;
        }
        return result;
    }
};