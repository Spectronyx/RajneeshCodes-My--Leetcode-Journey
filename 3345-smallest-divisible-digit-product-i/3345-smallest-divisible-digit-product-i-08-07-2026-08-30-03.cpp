class Solution {
public:
    int digitProduct(int n){
        int product = 1;

        while(n){
            product *= (n%10);
            n /= 10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(digitProduct(n)%t == 0){
                return n;
            }
            n++;
        }
        return 0;
    }
};