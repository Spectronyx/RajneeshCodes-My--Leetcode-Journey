class Solution {
public:
            int solve (vector<int> &nums,int l,int r){
        int prev = 0;
        int prevprev = 0;

        for(int i = l;i<= r;i++){
            int steal = nums[i]+prevprev;
            int skip = prev;
            prevprev = prev;
            prev = max(skip,steal);
        }
        return prev;

    }

    int rob(vector<int> &nums){
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if (n == 2) return max(nums[0],nums[1]);

     
        // maxprofit array which store the max profit till house i 
        int stealfirst = solve(nums,0,n-2);
        int skipfirst = solve(nums,1,n-1);


        return max(stealfirst,skipfirst);
        

    }
};