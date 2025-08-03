class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int res = 0;

        int left = 1;
        int right = n-2;

        //for rightmax and leftmax;
        int rmax = arr[right+1];
        int lmax = arr[left-1];

        while(left <= right){
            if(rmax <= lmax){

                res += max(0,rmax-arr[right]);
                rmax = max(rmax,arr[right]);
                right -= 1;

            }else{
                res += max(0,lmax-arr[left]);
                lmax = max(lmax,arr[left]);
                left += 1;
           }
        }
        return res;
    }
};