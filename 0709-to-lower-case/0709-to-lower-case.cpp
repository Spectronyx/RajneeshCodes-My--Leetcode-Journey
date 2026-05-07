class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for(auto ch: s){
            if(ch <= 'Z' && ch >= 'A')
                ans += ch-'A'+'a';
            else
            ans += ch;
        }
        return ans;
    }
};