class Solution {
public:
    int rows,cols;
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        rows=mat.size();
        cols = mat[0].size();
        vector<vector<int>> result(rows,vector<int>(cols,-1));
        
        queue<pair<int,int>> q;
        
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i,j});
                }
            }
        }


        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int i = p.first;
            int j = p.second;


            for(auto dir: directions){
                int new_i = i+dir[0];
                int new_j = j+dir[1];


                if(new_i >= 0 && new_j >= 0 && new_j < cols && new_i < rows && result[new_i][new_j] == -1 ){
                    q.push({new_i,new_j});
                    result[new_i][new_j] = 1+result[i][j];
                }
            }
        }
        return result;
    }
};