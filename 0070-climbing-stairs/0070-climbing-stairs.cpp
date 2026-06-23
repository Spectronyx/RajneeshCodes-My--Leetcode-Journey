// class Solution {
// public:
//     int arr[46];
//     int solve(int n){
//         if(n == 1) return 1;
//         if(n == 2) return 2;

//         if(arr[n] != -1){
//             return arr[n];
//         }

//         return arr[n] = solve(n-2)+solve(n-1);
//     }
//     int climbStairs(int n) {
//         memset(arr,-1,sizeof(arr));
//         return solve(n);
//     }
// };

// iterative solution
class Solution {
public:
    int climbStairs(int n){
        if(n == 1) return 1;
        if(n == 2) return 2;

        int prev1 = 2;
        int prev2 = 1;

        for(int i = 3;i<= n;i++){
            int current = prev1+prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};