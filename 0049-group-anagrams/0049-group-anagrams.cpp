class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> mp;
        
        for (auto& s : strs) {
            array<int, 26> arr = {};
            for (char ch : s)
                arr[ch - 'a']++;
            mp[arr].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& [k, v] : mp)
            result.push_back(v);
        
        return result;
    }
};