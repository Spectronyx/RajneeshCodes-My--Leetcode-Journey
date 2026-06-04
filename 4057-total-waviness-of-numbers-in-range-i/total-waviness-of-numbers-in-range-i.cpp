class Solution {
public:
    int isPeak(int num) {
        vector<int> arr;
        int ans = 0;

        while (num) {
            arr.push_back(num % 10);
            num /= 10;
        }
        int n = arr.size();
        reverse(arr.begin(), arr.end());

        for (int i = 1; i < n - 1; i++) {
            if ((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) ||
                (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])) {
                ans++;
            }
        }
        return ans;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;
        if (num2 < 100)
            return 0;
        for (int i = num1; i <= num2; i++) {
            int s = isPeak(i);
            ans += s ;
        }
        return ans;
    }
};