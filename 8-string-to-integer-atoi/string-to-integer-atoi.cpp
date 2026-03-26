class Solution {
public:

    const int INT_MIN_VAL = -2147483648;
    const int INT_MAX_VAL = 2147483647;

    // recruseive helper
    int helper(string &s, int i, long long num, int sign){
        // if we are you out of bounds or at a non digit, return
        if(i >= s.size() || !isdigit(s[i])){
            return (int)(sign*num);
        }

        // update the name with current digit
        num = num*10 +(s[i] - '0');

        // clamp if overflow
        if(sign * num <= INT_MIN_VAL) return INT_MIN_VAL;
        if(sign * num >= INT_MAX_VAL) return INT_MAX_VAL;

        // return the helper for the next character
        return helper(s,i+1,num,sign);
    }

    int myAtoi(string s) {
        int i = 0;

        // skip leading whitespaces
        while(i < s.size() && s[i] == ' ') i++;

        // handle sign 
        int sign = 1;
        if(i < s.size() && (s[i] == '+' || s[i]== '-')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        // callign the recrusive helperr
        return helper(s,i,0,sign);
    }
};