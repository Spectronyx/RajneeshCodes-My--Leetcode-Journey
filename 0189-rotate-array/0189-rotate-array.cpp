class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int i,j;
        k = k%n;
        //reverse last k elements
        for(i = n-k,j = n-1;i < j;i++,j--){
            swap(nums[i],nums[j]);
        } 
        
        //reverse first n-k elements
        for(i = 0,j = n-k-1;i < j;i++,j--){
            swap(nums[i],nums[j]);
        }

        //reverse the whole list
        for(i = 0,j = n-1;i <j;i++,j--){
            swap(nums[i],nums[j]);
        }
    }
};