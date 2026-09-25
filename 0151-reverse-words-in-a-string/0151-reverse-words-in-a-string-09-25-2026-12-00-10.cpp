class Solution {
public:
    string reverseWords(string s) {
        // reverse kar do
        reverse(s.begin(),s.end());

        int l = 0;
        int r = 0;
        int n = s.length();
        int i = 0;


        while(i < n){
            while(i < n && s[i] != ' '){
                s[r++] = s[i++];
            }

            if(l < r){
                reverse(s.begin()+l,s.begin()+r);

                s[r] = ' ';
                r++;
                l = r;
            }
            i++;
        }
        s = s.substr(0,r-1);
        return s;
    }

    
};