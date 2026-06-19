class Solution {
public:
    int m, n;

    vector<vector<int>> directions{
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    void dfs(vector<vector<int>>& grid, int i, int j){

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1){
            return;
        }

        // remove boundary-connected land
        grid[i][j] = 0;

        for(auto &dir : directions){
            dfs(grid,
                i + dir[0],
                j + dir[1]);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // First column and last column
        for(int i = 0; i < m; i++){

            if(grid[i][0] == 1)
                dfs(grid, i, 0);

            if(grid[i][n-1] == 1)
                dfs(grid, i, n-1);
        }

        // First row and last row
        for(int j = 0; j < n; j++){

            if(grid[0][j] == 1)
                dfs(grid, 0, j);

            if(grid[m-1][j] == 1)
                dfs(grid, m-1, j);
        }

        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};