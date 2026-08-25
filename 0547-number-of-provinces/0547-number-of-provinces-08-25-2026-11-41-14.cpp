class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj,int src,vector<int> &visited){
        visited[src] = 1;

        for(auto ngbr: adj[src]){
            if(!visited[ngbr]){
                dfs(adj,ngbr,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<int> visited(n,0);

        // creating adj from matrix
        unordered_map<int,vector<int>> adj;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // traversal

        for(int i = 0;i < isConnected.size();i++){
            if(visited[i]==0){
                dfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};