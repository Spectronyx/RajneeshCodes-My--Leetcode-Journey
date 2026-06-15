class Solution {
public:
    vector<int> buildLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while(i < m) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
    }
    int strStr(string text, string pattern) {
    if(pattern.empty()) return 0;

    vector<int> lps = buildLPS(pattern);

    int i = 0; // text pointer
    int j = 0; // pattern pointer

    while(i < text.size()) {

        if(text[i] == pattern[j]) {
            i++;
            j++;
        }

        if(j == pattern.size()) {
            return i - j;
        }
        else if(i < text.size() &&
                text[i] != pattern[j]) {

            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return -1;
    }
};