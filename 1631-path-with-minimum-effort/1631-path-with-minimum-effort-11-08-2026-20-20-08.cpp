class Solution {
public:
    vector<vector<int>> directions{{1,0},{0,1},{-1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        //effort, row,col
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto [effort,pos] = pq.top();
            pq.pop();

            int x = pos.first;
            int y = pos.second;

            if(x == n-1 && y == m-1){
                return effort;
            }

            if(effort > dist[x][y]) continue;

            for(auto dir: directions){
                int xx = dir[0]+x;
                int yy = dir[1]+y;


                if(xx >= 0 && yy >= 0 && xx < n && yy < m){
                    int diff = abs(heights[x][y] - heights[xx][yy]);
                    int newEffort = max(effort,diff);

                    if(newEffort < dist[xx][yy]){
                        dist[xx][yy] = newEffort;
                        pq.push({newEffort,{xx,yy}});
                    }
                }
            }
        }
        return 0;
    }
};