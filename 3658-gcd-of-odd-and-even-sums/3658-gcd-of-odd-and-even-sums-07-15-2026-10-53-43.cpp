class Solution {
public:
    int gcd(int a,int b){
        while(b){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        // int sumOdd = 0;
        // int sumEven = 0;

        // for(int i = 1,j = 2 ; n > 0;i += 2, j+= 2){
        //     sumOdd += i;
        //     sumEven += j;
        //     n--;
        // }

        long long sumOdd = (long long)n*n;
        long long sumEven = (long long)n*(n+1);

        return gcd(sumOdd,sumEven);
    }
};