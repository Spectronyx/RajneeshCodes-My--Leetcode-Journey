class Solution {
public:
    int n;
    unordered_set<string> st;
    int dp[301];
    bool solve(string &s,int index){
        if(index == n){
            return true;
        }

        if(dp[index] != -1) return dp[index];

        if(st.find(s) != st.end()) return true;

        for(int i = 1;i <= n;i++){
            string temp = s.substr(index,i);
            if((st.find(temp) != st.end()) && solve(s,index+i)) return dp[index] = true;    
        }
        return dp[index] =  false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        memset(dp,-1,sizeof(dp));
        for(auto word: wordDict){
            st.insert(word);
        }
        return solve(s,0);
    }
};