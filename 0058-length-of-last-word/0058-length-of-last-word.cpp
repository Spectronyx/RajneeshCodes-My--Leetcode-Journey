class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;

        // skipping the trailing zero
        while(i >= 0 && s[i] == ' '){
            i--;
        }

        // counting the len of the last word;
        int j = i;
        while(j >= 0 && s[j] != ' '){
            j--;
        }

        return i-j;
    }
};