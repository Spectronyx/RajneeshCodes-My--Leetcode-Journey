class Solution {
public:
    int rows ,cols;
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(vector<vector<int>>& grid,int i,int j){
        grid[i][j] = 2;

        for(auto dir: directions){
            int i_ = i+dir[0];
            int j_ = j+dir[1];

            if(i_ >= 0 && j_ >= 0 && i_ < rows && j_ < cols && grid[i_][j_] == 1){
                dfs(grid,i_,j_);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        for(int i = 0;i < rows;i++){
            if(grid[i][0] == 1 ){
                dfs(grid,i,0);
            }
            if(grid[i][cols-1] == 1){
                dfs(grid,i,cols-1);
            }
        }

        for(int j = 0;j < cols;j++){
            if(grid[0][j] == 1){
                dfs(grid,0,j);
            }

            if(grid[rows-1][j] == 1){
                dfs(grid,rows-1,j);
            }
        }


        int ans = 0;

        for(int i = 0; i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};