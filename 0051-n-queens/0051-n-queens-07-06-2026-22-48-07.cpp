class Solution {
public:
    int N;
    vector<vector<string>> result;
    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antiDiags;


    bool isSafe(vector<string> &board,int row,int col){
        //look upward
        for(int i = row-1;i >= 0;i--){
            if(board[i][col] == 'Q') return false;
        }

        //left diagnoal upward
        for(int i = row-1 ,j = col-1;i >= 0 && j >= 0;i--,j--){
            if(board[i][j] == 'Q') return false;
        }

        //left diagnoal upward
        for(int i = row-1 ,j = col+1;i >= 0 && j < N ;i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }

    void solve(vector<string> &board,int row){
        if(row >= N){
            result.push_back(board);
            return;
        }

        for(int col = 0;col < N;col++){
            int diag = row+col;
            int anti = row-col;

            if(cols.count(col) || diags.count(diag) || antiDiags.count(anti)) continue;

            cols.insert(col);
            diags.insert(diag);
            antiDiags.insert(anti);

            board[row][col] = 'Q';
            solve(board,row+1);
            board[row][col] = '.';

            cols.erase(col);
            diags.erase(diag);
            antiDiags.erase(anti);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        //sabse pehle board banao
        vector<string> board(n,string(n,'.'));
        N = n;
        solve(board,0);

        return result;
    }
};