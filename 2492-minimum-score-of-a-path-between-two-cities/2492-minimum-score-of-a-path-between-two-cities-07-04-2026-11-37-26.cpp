class Solution {
public:
    typedef  pair<int,int> P;
    void dfs(int i,vector<int> &visited,unordered_map<int,vector<P>> &adj,int &result){

        visited[i] = 1;

        for(auto &ngbr : adj[i]){
            int u = ngbr.first;
            int d = ngbr.second;

            result = min(result,d);
            if(!visited[u]){
                dfs(u,visited,adj,result);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        int result = INT_MAX;
        int m = roads[0].size();

        unordered_map<int,vector<P>> adj;
        // making adj
        for(auto r:roads){
            int u = r[0];
            int v = r[1];
            int d = r[2];


            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        vector<int> visited(n+1,0);
        // using dfs

        dfs(1,visited,adj,result);

        return result;
    }
};