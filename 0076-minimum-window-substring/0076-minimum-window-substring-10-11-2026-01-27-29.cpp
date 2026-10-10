#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        int n = s.size();
        int m = t.size();

        unordered_map<char, int> freq;
        int l = 0, r = 0;
        int si = -1;
        int minLen = INT_MAX;
        int count = 0;

        for (char ch : t)
            freq[ch]++;

        while (r < n) {
            if (freq[s[r]] > 0)
                count++;

            freq[s[r]]--;

            while (count == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    si = l;
                }

                freq[s[l]]++;

                if (freq[s[l]] > 0)
                    count--;

                l++;
            }

            r++;
        }

        return si == -1 ? "" : s.substr(si, minLen);
    }
};

