class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<char>>&board,int i,int j){
        if(i < 0 || i >= m || j < 0|| j >= n || board[i][j] != 'O'){
            return;
        }

        board[i][j] = 'S';

        for(auto &dir: directions){
            int new_i = i+dir[0];
            int new_j = j+dir[1];

            dfs(board,new_i,new_j);
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        // find all o's and connected to them

        // first row and last row
        for(int j = 0;j < n;j++){
            if(board[0][j] == 'O'){
                dfs(board,0,j);
            }
            if(board[m-1][j] == 'O'){
                dfs(board,m-1,j);
            }
        }

        // first cols and last col

        for(int i = 1;i < m-1;i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0);
            }
            if(board[i][n-1]){
                dfs(board,i,n-1);
            }
        }

        // sare o ko x bana do

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};