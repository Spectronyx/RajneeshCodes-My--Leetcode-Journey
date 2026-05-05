class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int maxLen = 0;

        unordered_set<char> charSet; 

        while(right < n){
            // if character dont exists
            if(charSet.find(s[right]) == charSet.end()){
                charSet.insert(s[right]);
                maxLen = max(maxLen, right-left+1);
                right++;
            }else{ // if the character dont exist
                charSet.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};