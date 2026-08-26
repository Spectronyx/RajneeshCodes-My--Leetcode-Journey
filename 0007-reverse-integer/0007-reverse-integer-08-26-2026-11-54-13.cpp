class Solution {
public:
    int reverse(int n) {
        bool isNegative = false;

        if(n >= INT_MAX || n <= INT_MIN) return 0;
        

        if(n < 0) isNegative = true;

        int x = abs(n);

        long long ans = 0;
        while(x){
            int ld = x%10;
            ans = (ans*10)+ld;
            x /= 10;
        }
        if(ans >= INT_MAX || ans*-1 <= INT_MIN) return 0;

        if(isNegative){
            return (int)(-1)*ans;
        }
        return (int)ans;
    }
};