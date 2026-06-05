#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    struct Result {
        long long count;      // how many numbers
        long long waviness;   // total waviness

        Result(long long c = 0, long long w = 0) {
            count = c;
            waviness = w;
        }
    };

    string limitNumber;

    map<tuple<int,int,int,bool,bool>, Result> dp;

    Result solveDP(int pos,
                   int prevDigit,
                   int secondPrevDigit,
                   bool started,
                   bool tight)
    {
        if (pos == limitNumber.size()) {
            return Result(1, 0);
        }

        auto state =
            make_tuple(pos,
                       prevDigit,
                       secondPrevDigit,
                       started,
                       tight);

        if (dp.count(state))
            return dp[state];

        int upperLimit =
            tight ? limitNumber[pos] - '0' : 9;

        Result answer;

        for (int currentDigit = 0;
             currentDigit <= upperLimit;
             currentDigit++)
        {
            bool nextTight =
                tight &&
                (currentDigit == upperLimit);

            if (!started && currentDigit == 0) {

                Result next =
                    solveDP(pos + 1,
                            -1,
                            -1,
                            false,
                            nextTight);

                answer.count += next.count;
                answer.waviness += next.waviness;
            }
            else {

                int extraWaviness = 0;

                if (secondPrevDigit != -1) {

                    bool peak =
                        secondPrevDigit < prevDigit &&
                        prevDigit > currentDigit;

                    bool valley =
                        secondPrevDigit > prevDigit &&
                        prevDigit < currentDigit;

                    if (peak || valley)
                        extraWaviness = 1;
                }

                Result next =
                    solveDP(pos + 1,
                            currentDigit,
                            prevDigit,
                            true,
                            nextTight);

                answer.count += next.count;

                answer.waviness +=
                    next.waviness +
                    1LL * extraWaviness * next.count;
            }
        }

        if (!tight)
            dp[state] = answer;

        return answer;
    }

    long long getTotalWaviness(long long x)
    {
        if (x < 0)
            return 0;

        limitNumber = to_string(x);
        dp.clear();

        return solveDP(0, -1, -1, false, true).waviness;
    }

    long long totalWaviness(long long num1,
                            long long num2)
    {
        return getTotalWaviness(num2)
             - getTotalWaviness(num1 - 1);
    }
};