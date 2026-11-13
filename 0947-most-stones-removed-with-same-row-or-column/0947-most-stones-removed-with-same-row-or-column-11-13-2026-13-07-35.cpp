class Solution {
public:
    void dfs(vector<vector<int>> &stones,int i,vector<bool>& visited){
        visited[i] = true;
        int row = stones[i][0];
        int col = stones[i][1];

        for(int index = 0;index < stones.size();index++){

            if(!visited[index]){
                if(stones[index][0] == row || stones[index][1] == col){
                    dfs(stones,index,visited);
                }
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int groups = 0;
        vector<bool> visited(n,false);

        for(int i = 0;i < n;i++){
            if(!visited[i]){
                dfs(stones,i,visited);
                groups++;
            }
        }


        return n - groups;
    }
};