class Solution {
    // Step 1: Compute LPS (Longest Prefix Suffix)
    static int[] computeLPS(String pat) {
        int n = pat.length();
        int[] lps = new int[n];
        int len = 0; // length of previous longest prefix suffix
        lps[0] = 0;

        int i = 1;
        while (i < n) {
            if (pat.charAt(i) == pat.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // Step 2: Use KMP to check if goal exists in s+s
    public boolean rotateString(String s, String goal) {
        if (s.length() != goal.length()) return false;
        String txt = s + s; // concatenated string
        String pat = goal;

        int n = txt.length();
        int m = pat.length();

        int[] lps = computeLPS(pat);
        int i = 0; // pointer for txt
        int j = 0; // pointer for pat

        while (i < n) {
            if (txt.charAt(i) == pat.charAt(j)) {
                i++;
                j++;
            }

            if (j == m) {
                return true; // pattern found
            } else if (i < n && txt.charAt(i) != pat.charAt(j)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
}
