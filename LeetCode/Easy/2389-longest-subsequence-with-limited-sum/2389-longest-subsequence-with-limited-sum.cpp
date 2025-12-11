class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> res;
        sort(nums.begin(),nums.end());

        for(int query: queries){
            int sum = 0;
            int count = 0;
            for(int i = 0;i< n;i++){
                if(sum + nums[i] > query){
                    break;
                }
                sum+= nums[i];
                count++;
            }
                res.push_back(count);
        }
        return res;
    }
};