class Solution {
public:
    // string reverseWords(string s) {
    //     stringstream ss(s);
    //     string token = "";
    //     string result = "";

    //     while (ss >> token){
    //         result = token +" "+result;
    //     }

    //     return result.substr(0,s.size());
    // }

    string reverseWords(string s){
        // story 
        // 1. reverse the whole string
        reverse(s.begin(),s.end());

        int i = 0;
        // hero honge l,r jo poora reverse karenge
        int l = 0,r = 0;
        int n = s.length();

        while(i < n){
            while(i < n && s[i] != ' '){
                s[r++] = s[i++];
            }
            if(l < r){ // l ... r 
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