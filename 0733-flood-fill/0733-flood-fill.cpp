class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // using multi source bfs 
        int rows = image.size();
        int cols = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int originalColor = image[sr][sc];
        image[sr][sc] = color;

        while(!q.empty()){
            int N = q.size();

            while(N--){
                auto curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto &dir: directions){
                    int new_i = i + dir[0];
                    int new_j = j+ dir[1];

                    if(new_i >= 0 && new_i< rows && new_j >= 0 && new_j < cols && color != image[new_i][new_j] && image[new_i][new_j] == originalColor){
                        image[new_i][new_j] = color;
                        q.push({new_i,new_j});
                    }
                }
            }
        }
        return image;
    }
};