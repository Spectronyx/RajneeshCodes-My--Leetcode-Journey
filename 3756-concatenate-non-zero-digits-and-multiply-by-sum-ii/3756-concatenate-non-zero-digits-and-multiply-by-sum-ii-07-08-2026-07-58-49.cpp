class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9+7;
        int n = s.length();
        
        vector<long long> prefixSum(n + 1, 0);
        vector<int> nonZeroPositions;
        
        // Store positions of non-zero digits and build prefix sum
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + (s[i] - '0');
            if (s[i] != '0') {
                nonZeroPositions.push_back(i);
            }
        }
        
        int m = nonZeroPositions.size();
        
        // Prefix array for numbers formed by non-zero digits
        vector<long long> prefixNum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            int digit = s[nonZeroPositions[i]] - '0';
            prefixNum[i + 1] = (prefixNum[i] * 10 + digit) % MOD;
        }
        
        // Precompute powers of 10
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            
            // Sum of all digits in [l, r]
            long long digitSum = prefixSum[r + 1] - prefixSum[l];
            
            // Find first and last non-zero positions in [l, r]
            auto left = lower_bound(nonZeroPositions.begin(), nonZeroPositions.end(), l);
            auto right = upper_bound(nonZeroPositions.begin(), nonZeroPositions.end(), r);
            
            long long num = 0;
            if (left != right) {
                int startIdx = left - nonZeroPositions.begin();
                int endIdx = right - nonZeroPositions.begin() - 1;
                
                // Get the number formed by non-zero digits from startIdx to endIdx
                num = (prefixNum[endIdx + 1] - 
                       (prefixNum[startIdx] * pow10[endIdx - startIdx + 1]) % MOD + MOD) % MOD;
            }
            
            ans.push_back((num * digitSum) % MOD);
        }
        
        return ans;
    }
};