class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        //swaping the adjacent elements;
        for(int i = 1;i< nums.size();i++){
            if(i%2 == 1){
                swap(nums[i],nums[i-1]);
            }
        }
        return nums;
    }
};