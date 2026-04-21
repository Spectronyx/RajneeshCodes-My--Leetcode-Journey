class Solution {
public:
    void  solve(int n,int open,int close,string curr,vector<string> &res){
        if(curr.length() == n*2){
            res.push_back(curr);
            return;
        }

        if (open < n) solve(n,open+1,close,curr+'(',res);
        if(open > close){
            solve(n,open,close+1,curr+')',res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(n,0,0,"",res);
        return res;
    }
};