class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // tow fixed sized arrays to check the track the last seen position
        int m1[256] = {0};
        int m2[256] = {0};

        // get the size of the strings
        int n = s.size();

        // traverse the each character of the string
        for (int i = 0; i < n; i++){
            // if the previous position differ return false
            if(m1[s[i]] != m2[t[i]]) return false;

            // update the position
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }
        return true;
    }
};