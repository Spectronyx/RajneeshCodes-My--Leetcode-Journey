class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> lastseen(256,-1);
        int left = 0;
        int maxLen = 0;

        for(int right = 0;right < n;right++){
            char c = s[right];

            // Duplicate found in the window
            if(lastseen[c] >= left){
                left = lastseen[c]+1;
            }

            lastseen[c] = right;
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;

    }
};