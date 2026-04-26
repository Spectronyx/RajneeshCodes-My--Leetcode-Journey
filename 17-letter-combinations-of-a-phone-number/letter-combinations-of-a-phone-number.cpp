class Solution {
public:
    vector<string> result;

    void solve(int idx, string &arr, string &temp, unordered_map<char,string> &mp){
        if(idx >= arr.size()){
            result.push_back(temp);
            return;
        }

        char ch = arr[idx];
        string str = mp[ch];

        for(int i = 0; i < str.size(); i++){
            temp.push_back(str[i]);
            solve(idx+1, arr, temp, mp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};

        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";
        solve(0, digits, temp, mp);

        return result;
    }
};