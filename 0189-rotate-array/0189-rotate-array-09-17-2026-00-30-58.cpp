class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        k = k%nums.size();

        // pehle poora array reverse kar do
        reverse(nums.begin(),nums.end());

        // ab suruaat ke k elements reverse kar do
        reverse(nums.begin(),nums.begin()+k);

        // ab baki elements ko reverse kar do
        reverse(nums.begin()+k,nums.end());
        
    }
};