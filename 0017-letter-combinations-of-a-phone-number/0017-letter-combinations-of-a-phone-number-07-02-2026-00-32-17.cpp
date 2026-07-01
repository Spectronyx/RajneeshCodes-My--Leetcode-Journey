class Solution {
public:
    vector<string> result;
    vector<string> mp{
        "","","abc","def",
        "ghi","jkl","mno",
        "pqrs","tuv","wxyz"
    };

    void solve(string &digits,int i,string &curr){
        if(i == digits.size()){
            result.push_back(curr);
            return;
        }

        string letters = mp[digits[i]-'0'];

        for(auto ch: letters){
            curr.push_back(ch);
            solve(digits,i+1,curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        string curr;

        solve(digits,0,curr);
        return result;

    }
};