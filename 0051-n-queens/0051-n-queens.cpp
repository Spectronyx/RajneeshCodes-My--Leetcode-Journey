// class Solution {
// public:
//     vector<vector<string>> result;
//     int N;
//     bool isValid(vector<string> &board,int row, int col){
//         // check the attack from up
//         for(int i = row-1;i >= 0;i--){
//             if(board[i][col] == 'Q') return false;
//         }

//         // check for the left diagonal
//         for(int i = row-1, j = col -1; i>= 0 &&j >= 0;i--,j--){
//             if(board[i][j] == 'Q') return false;
//         }

//         // check for the right diagonal
//         for(int i = row-1, j = col +1; i >= 0 &&j < N;i--,j++){
//             if(board[i][j] == 'Q') return false;
//         }
//         return true;
//     }
//     void solve(vector<string> &board,int row){
//         if(row == N){
//             result.push_back(board);
//             return;
//         }

//         for(int col = 0;col < N;col++){
//             if(isValid(board,row,col)){
//                 board[row][col] = 'Q';
//                 solve(board,row+1);
//                 board[row][col] = '.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         N = n;
//         vector<string> board(n,string(n,'.'));
//         solve(board,0);

//         return result;
//     }
// };

class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antidiags;
    vector<vector<string>> result;
    int N;

    void solve(vector<string> &board,int row){
        if(row == N){
            result.push_back(board);
            return;
        }

        for(int col = 0;col < N;col++){
            int diagConstant = row+col;
            int antidiagConstant = col-row;

            if(cols.find(col) != cols.end() || diags.find(diagConstant) != diags.end() || antidiags.find(antidiagConstant) != antidiags.end()){
                continue;
            }

            // fil the data and call solve
            cols.insert(col);
            diags.insert(diagConstant);
            antidiags.insert(antidiagConstant);
            board[row][col] = 'Q';

            solve(board,row+1);

            cols.erase(col);
            diags.erase(diagConstant);
            antidiags.erase(antidiagConstant);
            board[row][col] = '.';

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n,string(n,'.'));
        solve(board,0);

        return result;
    }
};