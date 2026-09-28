class Solution {
public:
    int myAtoi(string s) {
       if(s.empty()) return 0;

        const long long maxi = INT_MAX;
        const long long mini = INT_MIN;

        int n = s.size();
        int i = 0;


        while(i < n && s[i] == ' '){
            i++;
        }

        if(i == n){
            return 0;
        }

        int sign = 1;
        if(s[i] == '+'){
            i++;
        }else if(s[i] == '-'){
            sign = -1;
            i++;
        }


        long long res = 0;
        while(i < n && isdigit(s[i])){
            int digit = s[i]-'0';
            res = res * 10 + digit;

            if(sign*res <= mini){
                return mini;
            }
            if(sign*res >= maxi){
                return maxi;
            }
            i++;
        }

        return (int)res*sign;

        
    }
};