class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> ans(rows,vector<int>(cols,-1));

        int total = rows*cols;

        for(int i = 0;i < rows;i++){
            for(int j = 0;j< cols;j++){
                int oldindex = i*cols+j;
                int newindex = (oldindex+k)%total;
                int newRow = newindex/cols;
                int newCol = newindex%cols;

                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;

    }
};