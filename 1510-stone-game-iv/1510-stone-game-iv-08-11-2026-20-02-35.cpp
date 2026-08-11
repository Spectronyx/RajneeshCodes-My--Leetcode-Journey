#include <vector>
class Solution {public:
    bool winnerSquareGame(int n) {
        // dp[i] represents whether the current player can guarantee a win with 'i' stones remaining.
        // Base case: dp[0] is false, because 0 stones means no moves can be made (current player loses).
        std::vector<bool> dp(n + 1, false);

        // Compute the winning strategy for all stone states from 1 up to n
        for (int i = 1; i <= n; ++i) {
            // Try every possible valid move: removing a perfect square number of stones (k * k)
            for (int k = 1; k * k <= i; ++k) {
                // If removing k * k stones transitions the game to a state where the next player 
                // (now the opponent) is guaranteed to lose, then the current player can force a win.
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // Optimisation: One winning transition is enough to claim victory for this state
                }

            }
        }

        // Return the game result for the initial state with n stones (Alice's turn)
        return dp[n];
    }
};


