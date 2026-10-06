class Solution {
public:
    vector<int> dp;
    bool solve(string &s,int index,unordered_set<string>& dict){
        if(index == s.size()){
            return true;
        }

        if(dp[index] != -1){
            return dp[index];
        }
        for(int i = index;i< s.size();i++){
            string word = s.substr(index,i-index+1);
            if(dict.count(word)){
                if(solve(s,i+1,dict)){
                    return dp[index] = true;
                }
            }
        }
        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        dp.resize(s.size(),-1);
        return solve(s,0,dict);
    }
};