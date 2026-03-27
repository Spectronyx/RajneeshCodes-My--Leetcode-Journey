// class Solution {
// public:
//     int t[1001][1001];
//     bool solve(string &s,int i,int j){
//         if(i >= j) return 1;

//         if(t[i][j] != -1){
//             return t[i][j];
//         }

//         if(s[i]==s[j]){
//             return t[i][j] =  solve(s,i+1,j-1);
//         }else{
//             return t[i][j] = 0;
//         }
//     }
//     string longestPalindrome(string s) {
//         // naive approach me sab pandindrome check karne padege
//         // reverse karke check kar sakte h
//         // two pointer approach lagegi
//         int n = s.size();
//         memset(t,-1,sizeof(t));
//         int maxlen = INT_MIN;
//         int sp = 0;

//          for(int i =0;i< n;i++){
//              for(int j = i;j < n;j++){
//                 if(solve(s,i,j)){
//                     if(j-i+1> maxlen){
//                         maxlen = j-i+1;
//                         sp = i;
//                     }
//                 }

//              }
//          }

//          return s.substr(sp,maxlen);
//     }
// };

class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length();
        // state t[i][j] == true , s[i]...[j] is a longestPalindrome
        vector<vector<bool>> t(n,vector<bool>(n));


        int maxL = 0;
        int sp = 0;
        // sab diagonal elements palindrome hi honge
        for(int i =0;i< n;i++){
            t[i][i] = true;
            maxL = 1;
        }

        for(int L = 2;L <= n;L++){
            for(int i =0;i< n-L+1;i++){
                int j = i+L-1;

                if(s[i]==s[j] && L==2){
                    t[i][j] = true;
                    maxL = 2;
                    sp = i;
                }else if(s[i]==s[j] && t[i+1][j-1]==true){
                    t[i][j] = true;
                    if(j-i+1 > maxL){
                        maxL = j-i+1;
                        sp = i;
                    }
                }else{
                    t[i][j] = false;
                }
            }
        }
        return s.substr(sp,maxL);
    }
};

