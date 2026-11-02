class Solution {
public:

    vector<vector<int>> directions{{1,0},{0,1},{0,-1},{-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int originalColor = image[sr][sc];
        image[sr][sc] = color;

        while(!q.empty()){
            int N = q.size();

            while(N--){
                auto front = q.front();
                q.pop();

                int i = front.first;
                int j = front.second;

                for(auto dir: directions){
                    int new_i = dir[0]+i;
                    int new_j = dir[1]+j;

                    if(new_i >= 0 && new_j >= 0 && new_i < rows && new_j < cols && image[new_i][new_j] != color && image[new_i][new_j] == originalColor){
                        image[new_i][new_j] = color;
                        q.push({new_i,new_j});
                    }
                }
                
            }
        }
        return image;
    }
};