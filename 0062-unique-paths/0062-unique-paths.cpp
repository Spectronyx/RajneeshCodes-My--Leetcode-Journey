class Solution {
public:
    int dp[101][101];
    int solve(int m,int n,int i,int j){
        // agar bahar chale gaye toh
        if(i >= m || j >= n) return 0;
        // base case
        if(i == m-1 && j == n-1) return 1;

        // agar memoized array me pada hai pehle se
        if(dp[i][j] != -1) return dp[i][j];

        // har case me 2 directions possible hai
        // ya to right jao ya down

        return dp[i][j] =  solve(m,n,i+1,j)+solve(m,n,i,j+1);
        
        
    }
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        memset(dp,-1,sizeof(dp));
        return solve(m,n,0,0);
    }
};