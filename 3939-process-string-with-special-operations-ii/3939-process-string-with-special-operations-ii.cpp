class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();

        long long L = 0;

        for(int i = 0;i < n;i++){
            if(s[i] == '*'){
                if(L > 0)
                    L--;
            }else if(s[i] == '%'){
                continue;
            }else if(s[i] == '#'){
                L *= 2;
            }else{ // koi char a se z ka
                L++;
            }
        }

        if(k >= L ) return '.';

        // reverse iterate
        for(int i = n-1;i>= 0;i--){
            if(s[i] == '#'){
                L = L/2;
                k = (k>= L) ? k-L : k;
            }else if(s[i] == '*'){
                L++;
            }else if(s[i] == '%'){
                k = L-k-1;
            }else{  //agar a se z ke beech ka char h
                L--;
            }

            if(k == L){
                return s[i];
            }
        }

        return '.';
        
    }
};