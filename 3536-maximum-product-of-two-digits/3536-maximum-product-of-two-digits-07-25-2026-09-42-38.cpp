class Solution {
public:
    int maxProduct(int n) {
        int maxi = INT_MIN;
        int secMaxi = INT_MIN;

        while(n > 0){
            int digit = n%10;
            n /= 10;

            if(digit >= maxi){
                secMaxi = maxi;
                maxi = digit;
            }else if(digit > secMaxi){
                secMaxi = digit;
            }
        }
        return maxi*secMaxi;
    }
};