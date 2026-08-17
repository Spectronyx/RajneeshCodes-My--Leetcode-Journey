class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);

        for(auto ch:s){
            freq[ch-'a']++;
        }

        for(auto ch:t){
            freq[ch-'a']--;
        }

        for(auto num: freq){
            if(num != 0){
                return false;
            }
        }

        return true;
    }
};