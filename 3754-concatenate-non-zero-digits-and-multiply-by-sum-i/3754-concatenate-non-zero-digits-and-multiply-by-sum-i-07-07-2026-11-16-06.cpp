class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        if (n == 0) return 0;
        string num = "";

        while(n){
            int ld = n%10;
            if(ld!=0){
                num += to_string(ld);
            }
            ans = ans +ld;
            n/=10;
        }
        reverse(num.begin(),num.end());
        int nums = stoi(num);
        return  nums*ans;
    }
};