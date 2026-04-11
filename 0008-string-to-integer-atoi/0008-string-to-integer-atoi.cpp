class Solution {
public:
    const int INT_MIN_VAL = INT_MIN;
    const int INT_MAX_VAL = INT_MAX;

    int helper(string &s, int i, long long num,int sign){
        // if we are out of bound and non char
        if(i >= s.size() || !isdigit(s[i])) return (int)(num*sign);

        // update the num with current digit
        num = num* 10 + (s[i]-'0');

        // clamp if overflow 
        if(sign *num <= INT_MIN_VAL) return INT_MIN_VAL;
        if(sign * num >= INT_MAX_VAL) return INT_MAX_VAL;

        return helper(s,i+1,num,sign);

    }

    int myAtoi(string s) {
        // ignore the whitespaces
        int i = 0;
        while(i< s.size() && s[i] == ' '){
            i++;
        }

        // handle the sign 
        int sign = 1;
        if( i< s.size() && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return helper(s,i,0,sign);
    }
};