class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        // Count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Convert map to vector
        vector<pair<char, int>> arr;

        for (auto& [ch, count] : freq) {
            arr.push_back({ch, count});
        }

        // Sort by frequency descending
        sort(arr.begin(), arr.end(),
            [](auto& a, auto& b) {
                return a.second > b.second;
            });

        // Build answer
        string ans;

        for (auto& [ch, count] : arr) {
            ans += string(count, ch);
        }

        return ans;
    }
};