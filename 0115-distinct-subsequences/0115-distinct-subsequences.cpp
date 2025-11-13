class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        return choices(s,t,i,j,n,m,dp);
    }
    int choices(string &s,string &t,int i,int j,int n,int m,vector<vector<int>> &dp){
        //base case 
        //if we made the string 
        if(j == m) return 1;
        if(i == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = choices(s,t,i+1,j+1,n,m,dp) + choices(s,t,i+1,j,n,m,dp);
        }else{
            return dp[i][j] = choices(s,t,i+1,j,n,m,dp);
        }

    }
};