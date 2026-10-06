class Solution {
public:
    vector<bool> colUsed;
    vector<bool> diag1;
    vector<bool> diag2;
    vector<vector<string>> ans;

    void solve(vector<string>& board, int row) {
        int n = board.size();

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            int d1 = row - col + n - 1;
            int d2 = row + col;

            if (colUsed[col] || diag1[d1] || diag2[d2]) {
                continue;
            }

            board[row][col] = 'Q';
            colUsed[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            solve(board, row + 1);

            board[row][col] = '.';

            colUsed[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        colUsed.resize(n, false);
        diag1.resize(2 * n - 1, false);
        diag2.resize(2 * n - 1, false);

        solve(board, 0);

        return ans;
    }
};