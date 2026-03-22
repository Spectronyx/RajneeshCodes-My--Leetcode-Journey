class Solution {
public:
    bool isAnagram(string s, string t) {
        //  brute force approach
        // if(s.length() != t.length()) return false;

        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());

        // return s == t;

        // optimal approach
        int arr[26] = {0};

        for(char ch : s){
            arr[ch-'a']++;
        }

        for(char ch: t){
            arr[ch -'a']--;
            if(arr[ch-'a'] < 0) return false;
        }

        for(int num: arr){
            if(num != 0) return false;
        }
        return true;
    }
};