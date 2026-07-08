class Solution {
public:
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int N,M;

    void dfs(int i,int j,vector<vector<char>> &grid){
        if(i >= M || j >= N || j < 0 || i < 0 || grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';

        for(vector<int> dir: directions){
            int new_i = i+dir[0];
            int new_j = j+dir[1];

            dfs(new_i,new_j,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        M = grid.size();
        if(M == 0) return 0;
        N = grid[0].size();
        int count = 0;


        for(int i = 0;i < M;i++){
            for(int j = 0; j < N;j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};