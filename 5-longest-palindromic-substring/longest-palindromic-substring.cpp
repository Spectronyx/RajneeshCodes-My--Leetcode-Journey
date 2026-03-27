class Solution {
public:
    bool solve(string &s,int i,int j){
        if(i >= j) return true;

        if(s[i]==s[j]){
            return solve(s,i+1,j-1);
        }else{
            return false;
        }
    }
    string longestPalindrome(string s) {
        // naive approach me sab pandindrome check karne padege
        // reverse karke check kar sakte h
        // two pointer approach lagegi
        int n = s.size();
        int maxlen = INT_MIN;
        int sp = 0;

         for(int i =0;i< n;i++){
             for(int j = i;j < n;j++){
                if(solve(s,i,j)){
                    if(j-i+1> maxlen){
                        maxlen = j-i+1;
                        sp = i;
                    }
                }

             }
         }

         return s.substr(sp,maxlen);
    }
};