#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
private:
    // Precomputed factor mappings for digits 0-9 to ease calculation
    const std::vector<std::vector<std::pair<int, int>>> kFactorCounts = {
        {}, {}, {{2, 1}}, {{3, 1}}, {{2, 2}}, {{5, 1}}, {{2, 1}, {3, 1}}, {{7, 1}}, {{2, 3}}, {{3, 2}}
    };

    // Helper to subtract map b from map a, ensuring non-negative values
    std::unordered_map<int, int> subtract(std::unordered_map<int, int> a, const std::unordered_map<int, int>& b) {
        for (const auto& [p, cnt] : b) {
            a[p] = std::max(0, a[p] - cnt);
        }
        return a;
    }

    // Convert raw prime factor counts into the optimal (minimal length) group of single digits
    std::unordered_map<int, int> getDigitCounts(std::unordered_map<int, int> count) {
        std::unordered_map<int, int> res;
        
        res[8] = count[2] / 3; count[2] %= 3;
        res[9] = count[3] / 2; count[3] %= 2;
        res[7] = count[7];
        res[5] = count[5];
        
        res[4] = count[2] / 2; count[2] %= 2;
        res[3] = count[3];
        res[2] = count[2];

        // Optimize combinations of 2 and 3 into 6
        if (res[2] == 1 && res[3] == 1) {
            res[2] = 0; res[3] = 0; res[6] = 1;
        }
        // Optimize combinations of 3 and 4 into 2 and 6
        if (res[3] == 1 && res[4] == 1) {
            res[2] = 1; res[6] = 1; res[3] = 0; res[4] = 0;
        }
        return res;
    }

    // Construct standard lexicographically smallest string from digit counts
    std::string construct(const std::unordered_map<int, int>& factors) {
        std::string res = "";
        for (int digit = 2; digit <= 9; ++digit) {
            if (factors.count(digit)) {
                res += std::string(factors.at(digit), '0' + digit);
            }
        }
        return res;
    }

    int sumValues(const std::unordered_map<int, int>& m) {
        int sum = 0;
        for (const auto& [k, v] : m) sum += v;
        return sum;
    }

public:
    std::string smallestNumber(std::string num, long long t) {
        std::unordered_map<int, int> primeCount = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        long long temp = t;
        for (int p : {2, 3, 5, 7}) {
            while (temp % p == 0) { primeCount[p]++; temp /= p; }
        }
        if (temp > 1) return "-1"; // Invalid if prime factors > 7 are required

        int n = num.length();
        std::unordered_map<int, int> minFactorsNeeded = getDigitCounts(primeCount);
        int minLenRequired = sumValues(minFactorsNeeded);

        // If the prime factors alone require more digits than num's length, 
        // construct the absolute smallest number satisfying t
        if (minLenRequired > n) {
            return std::string(minLenRequired - minLenRequired, '1') + construct(minFactorsNeeded);
        }

        std::unordered_map<int, int> prefixPrimeCount = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        int firstZeroIndex = num.find('0');
        if (firstZeroIndex == std::string::npos) {
            firstZeroIndex = n;
            // Check if the original num is already valid
            for (char ch : num) {
                for (const auto& [p, cnt] : kFactorCounts[ch - '0']) prefixPrimeCount[p] += cnt;
            }
            bool is_valid = true;
            for (int p : {2, 3, 5, 7}) {
                if (prefixPrimeCount[p] < primeCount[p]) is_valid = false;
            }
            if (is_valid) return num;
        }

        // Reset prefix counts for backtracking verification
        prefixPrimeCount = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        for (int i = 0; i < firstZeroIndex; ++i) {
            for (const auto& [p, cnt] : kFactorCounts[num[i] - '0']) prefixPrimeCount[p] += cnt;
        }

        // Backtrack from right to left to change a prefix digit to a higher valid digit
        for (int i = n - 1; i >= 0; --i) {
            int d = num[i] - '0';
            if (i < firstZeroIndex) {
                for (const auto& [p, cnt] : kFactorCounts[d]) prefixPrimeCount[p] -= cnt;
            }
            if (i > firstZeroIndex) continue;

            for (int biggerDigit = d + 1; biggerDigit <= 9; ++biggerDigit) {
                std::unordered_map<int, int> replacedPrefix = prefixPrimeCount;
                for (const auto& [p, cnt] : kFactorCounts[biggerDigit]) replacedPrefix[p] += cnt;

                std::unordered_map<int, int> neededPrimes = subtract(primeCount, replacedPrefix);
                std::unordered_map<int, int> neededDigits = getDigitCounts(neededPrimes);
                int spaceAfterThisDigit = n - 1 - i;

                if (sumValues(neededDigits) <= spaceAfterThisDigit) {
                    int fillOnes = spaceAfterThisDigit - sumValues(neededDigits);
                    return num.substr(0, i) + std::to_string(biggerDigit) + std::string(fillOnes, '1') + construct(neededDigits);
                }
            }
        }

        // If it cannot fit in length n, dynamically compute the minimum length required 
        // to hold the entire factor pool of t
        int targetLen = std::max(n + 1, minLenRequired);
        int fillOnes = targetLen - minLenRequired;
        return std::string(fillOnes, '1') + construct(minFactorsNeeded);
    }
};
