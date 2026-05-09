class Solution {
public:
    int divide(int dividend, int divisor) {
        // overfolwo case
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        // result will be negative if sign differs
        bool negative = (dividend < 0) != (divisor < 0);

        //convert both to positive
        long long dd = abs((long long)dividend);
        long long dv = abs ((long long)divisor);
        long long result = 0;

        while(dd >= dv){
            long long temp = dv;
            long long multiple = 1;

            while(dd >= (temp << 1)){
                temp = temp<<1;
                multiple = multiple<<1;
            }

            dd -= temp;
            result += multiple;
        }

        return negative? -result: result;
    }
};