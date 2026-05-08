class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        // while(n>0){
        //     if(n&1){
        //         cnt += n&1;
        //     }
        //     n = n >> 1;
        // }

        // using bit manipulation
        while(n != 0){
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }
};