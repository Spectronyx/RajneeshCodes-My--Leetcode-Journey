class Solution {
public:
    // vector<int> singleNumber(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    //     vector<int> ans;
    //     for(auto num: nums){
    //         mp[num]++;
    //     }

    //     for(auto &p: mp){
    //         if(p.second == 1){
    //             ans.push_back(p.first);
    //         }
    //     }
    //     return ans;
    // }

    vector<int> singleNumber(vector<int> &num){
        vector<int> ans;

        long long xor_all = 0;

        for(auto n: num){
            xor_all ^= n;
        }

        long long diffbit = xor_all&(-xor_all);
        int num1 = 0;
        int num2 = 0;
        for(auto n: num){
            if(n & diffbit){
                num1 ^= n;
            }else{
                num2 ^= n;
            }
        }

        return {num1,num2};
    }
};