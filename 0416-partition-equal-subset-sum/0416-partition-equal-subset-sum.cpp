class Solution {
public:
    int N;
    vector<vector<int>> arr;
    bool solve(vector<int>& nums,int i,int target){
        
        if(target == 0) return true;

        if(i == nums.size())
            return false;    

        if(arr[i][target] != -1) return arr[i][target];    


        bool take = false;

        if(nums[i] <= target){
            take = solve(nums,i+1,target - nums[i]);
        }

        int skip = solve(nums,i+1,target);

        return arr[i][target] = skip || take;

    }
    bool canPartition(vector<int>& nums) {
        N = nums.size();
        int sum = 0;
        // the maain curx to this problme is wheather an you can partion the array or not
        for(int i = 0;i < N;i++){
            sum += nums[i];
        }
        arr.assign(nums.size(),vector<int>(sum+1,-1));

        if(sum%2 != 0) return false;
        return solve(nums,0,sum/2);
    }
};