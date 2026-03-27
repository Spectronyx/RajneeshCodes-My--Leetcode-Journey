// class Solution {
// public:
//     int solve(string &s,int i, int j){
//         vector<int> freq(26,0);
//         for(int start = i;start <= j;start++){
//             freq[s[start]-'a']++;
//         }

//         int mini = INT_MAX;
//         int maxi = INT_MIN;
//         for(auto it: freq){
//             if(it > 0){
//                 mini = min(mini,it);
//                 maxi = max(maxi,it);
//             }
//         }
//         return maxi-mini;
//     }
//     int beautySum(string s) {
//         int n = s.size();
//         int ans = 0;

//         for(int i =0;i< n;i++){
//             for(int j = i;j < n;j++){
//                 ans += solve(s,i,j);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int mini = INT_MAX;
                int maxi = INT_MIN;

                for (int f : freq) {
                    if (f > 0) {
                        mini = min(mini, f);
                        maxi = max(maxi, f);
                    }
                }

                ans += (maxi - mini);
            }
        }

        return ans;
    }
};