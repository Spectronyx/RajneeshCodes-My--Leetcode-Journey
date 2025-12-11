class Solution {
public:
    int binary_search(vector<int>&nums,int n,int target ){
        int l = 0,r = n-1;
        int resIndex = -1;
        int mid;

        while(l <= r){
            mid = l+(r-l)/2;

            if(target >= nums[mid]){
                resIndex = mid;
                l = mid+1;
            }
            else{
                r= mid-1;
            }  
        }
        return resIndex+1;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> res;
        sort(begin(nums),end(nums));

        //cumulative sum
        for(int i =1;i < n;i++){
            nums[i] += nums[i-1];
        }

        for(int query: queries){
            int count = binary_search(nums,n,query);
            res.push_back(count);
        }
        return res;
    }
};