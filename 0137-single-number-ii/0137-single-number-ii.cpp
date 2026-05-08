class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num: nums){
            mp[num]++;
        }

        for(auto &p : mp){
            if(p.second == 1){
                return p.first;
            }
        }
        return -1;
    }
};