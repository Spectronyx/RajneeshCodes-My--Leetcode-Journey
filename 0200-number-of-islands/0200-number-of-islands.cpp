class Solution {
public:
    int M,N;
    vector<vector<int>> directions{{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<char>>& grid,int i,int j){
        
        if(i >= M || j >= N || i < 0 || j < 0 || grid[i][j] != '1'){
            return;
        }

        grid[i][j] = '0';

        for(auto dir: directions){
            int new_i = i+dir[0];
            int new_j = j+dir[1];

            dfs(grid,new_i,new_j);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        M = grid.size();
        N = grid[0].size();

        int count = 0;

         for(int i = 0;i < M;i++){
            for(int j = 0;j < N;j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
         }
         return count;
    }
};