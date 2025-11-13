class Solution {
public:
    int solve(string &a,string &b,int i , int j,vector<vector<int>> &v){
       if(i == a.length() || j == b.length()) return 0;

       if(v[i][j] != -1) return v[i][j];

       if(a[i] == b[j]) return v[i][j] =  1+ solve(a,b,i+1,j+1,v);

       return v[i][j] = max(solve(a,b,i,j+1,v),solve(a,b,i+1,j,v)); 
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> v(text1.length(), vector<int>(text2.length(),-1));
        return solve(text1,text2,0,0,v);
    }
};