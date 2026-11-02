class Solution {
public:
    int rows,cols;
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& board,int i,int j){  
        board[i][j] = '#';
        for(auto dir: directions){
            int new_i = dir[0]+i;
            int new_j = dir[1]+j;

            if(new_i >= 0 && new_j >= 0 && new_i < rows && new_j < cols && board[new_i][new_j] == 'O'){
                dfs(board,new_i,new_j);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        // first and last col
        for(int i = 0;i < rows;i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0);
            }

            if(board[i][cols-1] == 'O'){
                dfs(board,i,cols-1);
            }
        }

        for(int j = 0;j < cols;j++){
            if(board[0][j] == 'O'){
                dfs(board,0,j);
            }

            if(board[rows-1][j] == 'O'){
                dfs(board,rows-1,j);
            }
        }


        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};