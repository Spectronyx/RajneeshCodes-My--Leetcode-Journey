class Solution {
public:
    bool isPerfectSquare(int n) {
        // using binary search
        int low = 1;
        int high = n;

        while(low <= high){
            int mid = low +(high-low)/2;
            long long square = 1LL * mid*mid;

            if(square == n){
                return true;
            }else if(square < n){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};