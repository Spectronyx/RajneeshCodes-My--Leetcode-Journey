class Solution {
public:
    vector<int> vec;
    int fibo(int n){
        if(n == 1){
            return 1;
        }
        if(n == 0) return 0;

        if(vec[n] != -1){
            return vec[n];
        }

        return vec[n] = fibo(n-1)+fibo(n-2); 
    }
    int fib(int n) {
        vec.resize(n+1,-1);
        return fibo(n);
    }
};