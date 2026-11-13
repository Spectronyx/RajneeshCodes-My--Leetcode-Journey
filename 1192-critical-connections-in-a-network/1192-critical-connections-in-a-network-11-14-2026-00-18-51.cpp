
class Solution {
public:
    int time;
    vector<int> dt, low;
    vector<vector<int>> ans;

    void dfs(int u, int parent,
             vector<bool>& visited,
             vector<vector<int>>& adj) {

        visited[u] = true;
        dt[u] = low[u] = ++time;

        for (auto v : adj[u]) {

            if (v == parent) continue;

            if (!visited[v]) {

                dfs(v, u, visited, adj);

                low[u] = min(low[u], low[v]);

                // Bridge condition
                if (low[v] > dt[u]) {
                    ans.push_back({u, v});
                }

            } else {
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        for (auto e : connections) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        time = 0;
        dt.assign(n, 0);
        low.assign(n, 0);
        ans.clear();

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1, visited, adj);
            }
        }

        return ans;
    }
};
