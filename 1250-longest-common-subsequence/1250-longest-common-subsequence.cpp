class Solution {
public:
    int solve(string &a,string &b,int i , int j,vector<vector<int>> &v){
       if(i == a.length() || j == b.length()) return 0;

       if(v[i][j] != -1) return v[i][j];

       if(a[i] == b[j]) return v[i][j] =  1+ solve(a,b,i+1,j+1,v);

       return v[i][j] = max(solve(a,b,i,j+1,v),solve(a,b,i+1,j,v)); 
    }

    int solveTab(string a,string b){
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1,0));
        for(int i = 1 ;i <= n;i++){
            for(int j = 1;j<= m;j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                } 
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> v(text1.length(), vector<int>(text2.length(),-1));
        return solveTab(text1,text2);
    }
};