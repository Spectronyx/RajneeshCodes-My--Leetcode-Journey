class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(auto num: nums){
            if(mp.find(num) != mp.end()){
                mp[num]++;
            }else{
                mp[num] = 1;
            }
        }

        for(auto& pair: mp){
            if(pair.second > nums.size()/3){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};