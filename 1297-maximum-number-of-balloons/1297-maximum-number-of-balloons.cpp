class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;

        for(auto ch: text){
            mp[ch]++;
        }

        int min1s = min(mp['a'],min(mp['b'],mp['n']));
        int min2s = min(mp['l'],mp['o'])/2;


        return min(min1s,min2s);
    }
};