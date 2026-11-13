class Solution {
public:
    void dfs(vector<vector<int>> &stones,int i,vector<bool>& visited){
        visited[i] = true;

        for(int index = 0;index < stones.size();index++){
            int row = stones[index][0];
            int col = stones[index][1];

            if(!visited[index]){
                if(stones[i][0] == row || stones[i][1] == col){
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