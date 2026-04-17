class Solution {
public:
    vector<int> vec;
    int fibo(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 0)
            return 0;

        if (vec[n] != -1) {
            return vec[n];
        }

        return vec[n] = fibo(n - 1) + fibo(n - 2);
    }
    // int fib(int n) {
    //     vec.resize(n+1,-1);
    //     return fibo(n);
    // }

    int fib(int n) {

        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        vector<int> vec(n + 1, -1);
        vec[0] = 0;
        vec[1] = 1;

        for (int i = 2; i <= n; i++) {
            vec[i] = vec[i - 1] + vec[i - 2];
        }

        return vec[n];
    }
};