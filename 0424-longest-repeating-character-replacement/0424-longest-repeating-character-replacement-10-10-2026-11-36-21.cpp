#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> mp;

        int left = 0, ans = 0, maxFreq = 0;

        for (int right = 0; right < n; right++) {
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);

            while ((right - left + 1) - maxFreq > k) {
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

