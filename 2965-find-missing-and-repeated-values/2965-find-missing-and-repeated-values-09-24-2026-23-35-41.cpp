class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        // Flatten the grid
        vector<int> a;

        for (auto arr : grid) {
            for (auto num : arr) {
                a.push_back(num);
            }
        }

        int n = a.size();

        // XOR all elements of array
        int xoor = 0;

        for (auto num : a) {
            xoor ^= num;
        }

        // XOR all numbers from 1 to n
        int exor = 0;

        for (int i = 1; i <= n; i++) {
            exor ^= i;
        }

        // repeating ^ missing
        int xr = xoor ^ exor;

        // Find a differing bit
        int bitNo = 0;
        // int bitNo = xr& -xr;

        while ((xr & (1 << bitNo)) == 0) {
            bitNo++;
        }

        int zero = 0;
        int one = 0;

        // Divide array elements into two groups
        for (int num : a) {

            if (num & (1 << bitNo)) {
                one ^= num;
            } 
            else {
                zero ^= num;
            }
        }

        // Divide numbers 1 to n into two groups
        for (int i = 1; i <= n; i++) {

            if (i & (1 << bitNo)) {
                one ^= i;
            } 
            else {
                zero ^= i;
            }
        }

        // Find which one is repeating
        int cnt = 0;

        for (int num : a) {
            if (num == zero) {
                cnt++;
            }
        }

        if (cnt == 2)
            return {zero, one};

        return {one, zero};
    }
};