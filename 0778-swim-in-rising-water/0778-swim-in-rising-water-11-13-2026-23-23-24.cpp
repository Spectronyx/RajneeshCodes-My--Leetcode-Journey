class Solution {
public:
    int n;
    vector<vector<int>> directions{{0,1},{1,0},{-1,0},{0,-1}};

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0],0,0});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int x = curr[1];
            int y = curr[2];

            // auto [cost,x,y] = curr;


            if(x == n-1 && y == n-1){
                return cost;
            }

            if(cost > dist[x][y]) continue;

            for(auto dir: directions){
                int new_i = dir[0]+x;
                int new_j = dir[1]+y;

                if(new_i >= 0 && new_j >= 0 && new_i < n && new_j < n){
                    int newCost = max(cost,grid[new_i][new_j]);

                    if(newCost < dist[new_i][new_j]){
                        dist[new_i][new_j] = newCost;

                        pq.push({newCost,new_i,new_j});
                    }
                }
            }
        }
        return -1;
    }
};