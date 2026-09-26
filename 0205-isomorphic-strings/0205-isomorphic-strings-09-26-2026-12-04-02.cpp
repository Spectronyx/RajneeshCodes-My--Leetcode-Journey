class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;

        if(s.size() != t.size()) return false;

        for(int i = 0;i < s.size();i++){
            char ch1 = s[i];
            char ch2 = t[i];


            if(mp1.count(ch1) && mp1[ch1] != ch2){
                return false;
            }
            if(mp2.count(ch2) && mp2[ch2] != ch1){
                return false;
            }

            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};