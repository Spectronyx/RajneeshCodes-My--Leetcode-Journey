class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int factor = 5;
        while(n){
            int res = n/factor;
            ans += res;
            if(res == 0){
                break;
            }
            factor = factor*5; 
        }
        return ans;
    }
};