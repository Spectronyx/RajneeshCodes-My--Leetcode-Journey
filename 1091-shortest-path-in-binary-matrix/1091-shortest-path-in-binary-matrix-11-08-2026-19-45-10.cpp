class Solution {
public:
    vector<vector<int>> directions{{0,-1},{0,1},{1,0},{1,-1},{1,1},{-1,-1},{-1,0},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // using the bfs
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        grid[0][0] = 1;

        while(!q.empty()){
            auto [pos,dist] = q.front();
            q.pop();

            int x = pos.first;
            int y = pos.second;

            //if destination reached
            if(x == n-1 && y == n-1) return dist;

            for(auto dir: directions){
                int xx = dir[0]+x;
                int yy = dir[1]+y;

                if(xx >= 0 && yy >= 0 && xx < n && yy < n&& grid[xx][yy] != 1){
                    q.push({{xx,yy},dist+1});
                    grid[xx][yy] = 1;
                }
            }
        }
        return -1;
    }
};